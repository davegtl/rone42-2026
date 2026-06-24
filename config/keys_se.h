#pragma once

#include <dt-bindings/zmk/keys.h>

/*
 * Swedish (sv-SE) keycode aliases.
 *
 * Your OS keyboard layout must be set to Swedish. These map the "logical"
 * Swedish characters onto the US physical-position keycodes (plus any
 * modifiers) that a Swedish layout expects. Used with &kp, and composable
 * with LS()/RA()/RC() in the keymap.
 */

/* number row — base digits sit on the same positions */
#define SE_N1 N1
#define SE_N2 N2
#define SE_N3 N3
#define SE_N4 N4
#define SE_N5 N5
#define SE_N6 N6
#define SE_N7 N7
#define SE_N8 N8
#define SE_N9 N9
#define SE_N0 N0

/* diacritic letters (direct positions on a Swedish layout) */
#define SE_A_RING   LBKT   /* å   (US '[') */
#define SE_A_UMLAUT SQT    /* ä   (US '\'') — your base layer also uses &kp SQT  */
#define SE_O_UMLAUT SEMI   /* ö   (US ';')  — your base layer also uses &kp SEMI */

/* punctuation */
#define SE_COMMA    COMMA          /* , */
#define SE_DOT      DOT            /* . */
#define SE_MINUS    SLASH          /* -  (US '/') */
#define SE_PLUS     MINUS          /* +  (US '-') */
#define SE_QUESTION LS(MINUS)      /* ?  (Shift + the +/? key) */
#define SE_QMARK    LS(MINUS)      /* ?  (alias) */
#define SE_SLASH    LS(N7)         /* /  (Shift + 7) */
#define SE_STAR     LS(NON_US_HASH)/* *  (Shift of the '/* key) */

/* AltGr / shifted-symbol helpers */
#define SE_PIPE          RA(NON_US_BSLH) /* |  (AltGr + the <>| ISO key) */
#define SE_DOLLAR        RA(N4)          /* $  (AltGr + 4) */
#define SE_LEFT_BRACE    RA(N7)          /* {  (AltGr + 7) */
#define SE_RIGHT_BRACE   RA(N0)          /* }  (AltGr + 0) */
#define SE_LEFT_BRACKET  RA(N8)          /* [  (AltGr + 8) */
#define SE_RIGHT_BRACKET RA(N9)          /* ]  (AltGr + 9) */
