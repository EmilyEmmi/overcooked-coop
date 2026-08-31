## v1.1 (WIP)
### New features:
- Added Portuguese translation, available under Preferences -> Language (denpakei32)
- Made the Character Select menu accessible using the Z button in the menu, or through a menu option (previously, it could only be accessed using the /char-select command)
- Button prompts now appear for interacting with ingredients! Toggleable in Preferences.
- Added an option to hide the HUD to Preferences. This does not save.
### Adjustments
- Interacting with an ingredient on a counter while holding a plate no longer places the plate on the counter
    - This change can be toggled in Preferences
- Improved action priority- for example, if you're holding a bun and a bunch of ingredients are on the ground, the ingredients you're actually able to place on the burger have priority
- Bowser is now automatically dropped after 5 seconds, and he can't be regrabbed until another 5 seconds have passed
    - However, he also takes 4 times as long to recover from being thrown off the stage
- Changed various models and animations (denpakei32, WBMarioo)
- Changed icon for mushroom (denpakei32)
- Changed colors of various icons
- Ingredients on top of counters are deprioritzed for deletion when too many ingredients are present (this means they can only be deleted in rare circumstances)
- Ingredients now respawn if they fall into water
- You now always get asked if you'd like to join/practice, even in the lobby
- Added a version number in the bottom left corner of the menu
- Added a warning when using a Character Select version lower than v1.16.3
### Fixes
- The desync fix will now correct instances where players are placed in the wrong level
- Fixed occasional script errors in Koopa Kitchen
- Fixed the description for Host Options being "Host Options" instead of the actual description
- Fixed the cooking time not updating properly when transferring contents between pots/pans
- Fixed plate stacks of 3 or more getting seperated from each other
- Burgers and soup may no longer be plated while a pizza is already on the plate
- The ingredient cap can no longer delete items that players are already holding
- Spectators can no longer grab Bowser