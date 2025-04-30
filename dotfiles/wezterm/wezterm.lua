local wezterm = require('wezterm')
local theme = wezterm.plugin.require('https://github.com/neapsix/wezterm').moon

return {
    colors = theme.colors(),
    default_cursor_style = 'BlinkingBar',
    enable_tab_bar = false,
    window_frame = theme.window_frame(), -- needed only if using fancy tab bar
}
