#pragma once
// "Shortcut" build support (DS only).
//
// The stock gameyob.nds contains one small, empty, patchable block. The
// make_shortcut.py tool writes a ROM path and BIOS path into that block and
// replaces the banner (icon + title), producing a standalone .nds that boots
// straight into one game. If the block is left empty, GameYob behaves exactly
// as before (file chooser etc).
#ifdef DS

struct ShortcutConfig {
    char magic[16];   // "GYSHORTCUTv1" - located by the patch tool, do not change
    char rom[256];    // e.g. "/roms/gb/Pokemon Red.gb"
    char bios[256];   // e.g. "/bios/gbc_bios.bin" (may be empty)
};

// Defined in shortcut.cpp (separate TU on purpose so the compiler can't
// constant-fold the empty defaults away).
extern ShortcutConfig shortcutConfig;

static inline bool shortcutActive() { return shortcutConfig.rom[0] != '\0'; }

#else
static inline bool shortcutActive() { return false; }
#endif
