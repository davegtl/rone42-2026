# Rone — ZMK config (dongleless, Studio-ready, Swedish)

A fresh ZMK user-config for the **Rone** 42-key split (nice!nano v2 ×2).

- **Architecture:** dongleless. **Left = central** (has the nice!view), **right = peripheral**.
- **ZMK Studio:** enabled on the central, over USB.
- **Swedish:** OS layout must be set to Swedish; `config/keys_se.h` maps the `SE_*` aliases.
- **Display:** nice!view on the left half, stock widget (shows **left** battery, BT profile, layer).
- **Right-half battery on the screen:** the data is already being fetched to the central
  (`CONFIG_ZMK_SPLIT_BLE_CENTRAL_BATTERY_LEVEL_FETCHING`). Rendering it on the nice!view is
  the one remaining custom-widget step — see "Next step" below.

## Layout

```
Layers: 0 WIN   1 NUMB   2 NAV   3 ALPHS(F-keys)   4 CONF   5 OSX   6 CRED   7 CODE
        (+ two empty "reserved" layers for adding more in Studio without re-flashing)
```

- `&lt 7 D` on the base layer: tap = D, hold = CODE layer.
- Macros: `fika`, `admin`, `azure`, `kjell`, `lasso` (triggered by your thumb combos).
- `&studio_unlock` lives on NUMB, top-left.

## Build

This is a standard ZMK user-config. Push to GitHub and let the included GitHub Action build it,
or build locally.

**Outputs:** `rone_left` (flash to the **left** half), `rone_right` (right half),
and `settings_reset` (flash to either half first if pairing gets stuck).

Local build example:

```
west build -s zmk/app -d build/left  -b nice_nano_v2 -S studio-rpc-usb-uart \
    -- -DSHIELD=rone_left -DZMK_CONFIG="$(pwd)/config" -DCONFIG_ZMK_STUDIO=y
west build -s zmk/app -d build/right -b nice_nano_v2 \
    -- -DSHIELD=rone_right -DZMK_CONFIG="$(pwd)/config"
```

## Flash order (first time)

1. Flash `settings_reset` to **both** halves, then
2. Flash `rone_left` to the left, `rone_right` to the right.
3. Connect the left half to your computer over **USB** and open ZMK Studio. Trigger
   `&studio_unlock` (NUMB layer, top-left) to allow edits.

> Note: once you manage the keymap in Studio, later edits to `rone.keymap` won't apply
> unless you do "Restore Stock Settings" in Studio. Adding new *reserved* layers is the
> exception. So: get definitions right in the file first, then live in Studio.

## Things I changed / flagged

- **File names were scrambled** in your upload (contents didn't match names). Everything was
  recovered; this repo has the correct names.
- **`keys_se.h` was missing** (the file by that name held `.conf` text). Regenerated to cover
  every `SE_*` you use.
- **`&rgb_ug`** in the OSX layer was replaced with `&trans` — there's no RGB underglow on this
  board, and that binding would fail to build. Restore it if you add underglow.
- Layer `label` properties were renamed to `display-name` (ZMK changed this).

## Next step: right-half battery on the nice!view

The stock nice!view widget only draws the central battery. Showing the **right** half's battery
on the same screen needs a small custom LVGL widget that subscribes to the peripheral battery
state. The central already receives that data (fetching is on), so this is purely a display
addition — I'll provide it once you've confirmed this core firmware builds, boots, and connects
to Studio, so the custom display code never blocks your working build.
