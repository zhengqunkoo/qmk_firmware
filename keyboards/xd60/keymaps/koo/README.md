Do a vimdiff before editing, because keymap.c might have recent modifications not available in other maps.

keymap.c is the current flashed map
keymap.code tries to use *register_code instead of *register_mods
keymap.direct tries to send LSFT() codes directly instead of *register_mods
keymap.indirect uses *register_mods, and works well (except it doesn't work with i3)
