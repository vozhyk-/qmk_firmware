# vozhyk-'s keymap for ErgoDash

## Features

- Numbers shifted to the left so that (QWERTY) `1`, `2`, `3` are in the same position as on a row-staggered keyboard
  when holding Hyper (`KC_LGUI`) or Shift with the left pinky.
- `'`(QWERTY `z`) replaced with `Shift`, so that `Shift` is accessible by bending the left pinky down, like on a row-staggered keyboard.
- Hardware Programmer Dvorak-like layout - mapped to QWERTY keys and using macros to have different shifted and non-shifted keycodes.
- Modes for languages:
  - Belarusian (Latin) (mapped to Belarusian Latin QWERTY) with accented characters rearranged.
  - Polish (the default) (mapped to Polish QWERTY and Polish Programmer Dvorak) with macros for the "sz", "cz", "rz" combinations.
  - Japanese with keys for switching Japanese input modes (not used recently);
  - None (right `Alt` kept as is).
- Swap-hands and a mode for using it with both hands
- Ergoemacs-like Navigation layer
- A Symbol layer with symbols placed at Programmer Dvorak-like finger positions
- A Game mode with:
  - numbers and `'` at their regular positions;
  - more letters on the right side of the left half;
  - Hyper (`KC_LGUI`) at a regular keyboard's CapsLock position replaced with `\` to map it in games more easily
    and not press Win accidentally.
- A macro for switching tabs in most-recently used order with Control-Tab
- A Mac mode with:
  - Left (`Command`, `Control`, `Option`) on the bottom row.
  - Hyper mapped to `Command+Control+Option` to simulate the modifier missing in MacOS.
  - Most `Control-*` mappings replaced with `Command-*`.
  - Host OS detection that turns on Mac mode and Programmer Dvorak emulation for Mac and iOS hosts (which M1 Macs are detected as).

## Underglow

Used to indicate active modes:
- Programmer Dvorak emulation;
- game mode;
- Mac mode;
- Language mode:
  - Belarusian latin;
  - None;
  - no indication for Polish and Japanese.
- Swap-hands mode.
