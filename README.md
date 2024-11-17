# Add SOCD to any keyboard that runs QMK firmware

To add SOCD functionality to your keyboard, add the contents of the `socd.c` file to your keymap.c file and set 2 of your keys as:

| KEY      | FUNCTIONALITY | 
|----------|:-------------:|
| KC_F23   |  Enable SOCD  | 
| KC_F24   |  Disable SOCD | 

Or just change the keycodes in the switch statement in the code to fit your needs.