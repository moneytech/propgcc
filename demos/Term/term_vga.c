#include <propeller.h>
#include "term_vga.h"

static char default_palette[TERM_COLORTABLE_SIZE] =     
{                           // fgRGB  bgRGB    '
    0b111111, 0b000001,     // %%333, %%001    '0    white / dark blue
    0b111100, 0b010100,     // %%330, %%110    '1   yellow / brown
    0b100010, 0b000000,     // %%202, %%000    '2  magenta / black
    0b010101, 0b111111,     // %%111, %%333    '3     grey / white
    0b001111, 0b000101,     // %%033, %%011    '4     cyan / dark cyan
    0b001000, 0b101110,     // %%020, %%232    '5    green / gray-green
    0b010000, 0b110101,     // %%100, %%311    '6      red / pink
    0b001111, 0b000001      // %%033, %%003    '7     cyan / blue
};

static int vblank(TERM *term);

static TERM_OPS ops = {
	Term_out,
	vblank
};

/*
 * VGA_Text start function starts VGA on a cog
 * See header file for more details.
 */
TERM *vgaTerm_start(TERM_VGA *vgaTerm, int basepin)
{
    TERM *term = &vgaTerm->term;
    vgaText_t *vgaText = &vgaTerm->control;
    extern uint32_t binary_VGA_dat_start[];
    
    term->ops = &ops;
    term->screen = vgaTerm->screen;
    term->colors = vgaTerm->colors;
    term->screensize = VGA_TEXT_SCREENSIZE;
    term->lastrow = term->screensize - VGA_TEXT_COLS;
    term->col   = 0; // init vars
    term->row   = 0;
    term->rows = VGA_TEXT_ROWS;
    term->cols = VGA_TEXT_COLS;
    term->color = 0;
    term->flag = 0;

    vgaText->status = 0;
    vgaText->enable = 1;
    vgaText->pins   = basepin | 0x7;
    vgaText->mode   = 0b1000;
    vgaText->screen = (long) term->screen;
    vgaText->colors = (long) term->colors;
    vgaText->ht = VGA_TEXT_COLS;
    vgaText->vt = VGA_TEXT_ROWS;
    vgaText->hx = 1;
    vgaText->vx = 1;
    vgaText->ho = 1;
    vgaText->vo = 1;
    vgaText->hd = 512;
    vgaText->hf = 10;
    vgaText->hs = 75;
    vgaText->hb = 43;
    vgaText->vd = 480;
    vgaText->vf = 11;
    vgaText->vs = 2;
    vgaText->vb = 31;
    vgaText->rate = 80000000 >> 2;
      
    vgaTerm->cogid = cognew((void*)binary_VGA_dat_start, (void*)vgaText);
    
    // set main fg/bg color here
    Term_setColorPalette(term, default_palette);

    // blank the screen
    Term_clearScreen(term);
    
    return term;
}

/*
 * VGA_Text stop function stops VGA cog
 * See header file for more details.
 */
void vgaTerm_stop(TERM *term)
{
	TERM_VGA *vgaTerm = (TERM_VGA *)term;
    if(vgaTerm->cogid) {
        cogstop(vgaTerm->cogid);
    }
}

static int vblank(TERM *term)
{
	TERM_VGA *vgaTerm = (TERM_VGA *)term;
    return vgaTerm->control.status == VGA_TEXT_STAT_INVISIBLE;
}
