#include "shortcut.h"

// Must stay in .data (non-const, non-zero magic) so it ends up in the arm9
// binary where make_shortcut.py can find and overwrite it.
ShortcutConfig shortcutConfig = {
    {'G','Y','S','H','O','R','T','C','U','T','v','1','\0','\0','\0','\0'},
    {0},
    {0}
};
