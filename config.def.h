
/* key definitions, here the hotkeys for the basic workspaces-associated functions are defined, respectively select workspace,  add another worksapce, send program to another workspace and show the program(s) on the current workspace on the selected workspace(s) */
#define MODKEY Mod4Mask
#define TAGKEYS(KEY,TAG) \
	{ MODKEY,                       KEY,      view,           {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask,           KEY,      toggleview,     {.ui = 1 << TAG} }, \
	{ MODKEY|ShiftMask,             KEY,      tag,            {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask|ShiftMask, KEY,      toggletag,      {.ui = 1 << TAG} },


/* helper for spawning shell commands in the pre dwm-5.0 fashion */
/* Thanks to defining here with a shorthand notation how to execute a command in the shell lower in the file you have to write less and it makes the code more easily readable */
#define SHCMD(cmd) { .v = (const char*[]){ "/bin/sh", "-c", cmd, NULL } }

#include "movestack.c"
static const Key keys[] = {
	/* modifier                     key        function        argument */
	{ MODKEY,                       XK_d,      spawn,          {.v = dmenucmd } },   // open dmenu, by default on the top of the screen (this hotkey was chosen because it is more erconomical if you use the d-key 
	{ MODKEY,		        		XK_Return, spawn,          SHCMD("alacritty") },  // open terminal, terminal is chosen higher in the file
	{ MODKEY,                       XK_b,      togglebar,      {0} },   // toggle show/hide panel
	{ MODKEY,                       XK_j,      focusstack,     {.i = +1 } },// change focus to another window on that workspace
	{ MODKEY,                       XK_k,      focusstack,     {.i = -1 } },
	{ MODKEY,                       XK_i,      incnmaster,     {.i = +1 } },  // increase number of windows in the master-area
	{ MODKEY,                       XK_e,      incnmaster,     {.i = -1 } },
	{ MODKEY,                       XK_h,      setmfact,       {.f = -0.05} },	// change vertical split-ratio between master and stack
	{ MODKEY,                       XK_l,      setmfact,       {.f = +0.05} },
	{ MODKEY|ShiftMask,             XK_j,      movestack,      {.i = +1 } },
	{ MODKEY|ShiftMask,             XK_k,      movestack,      {.i = -1 } },
	{ MODKEY,                       XK_Return, zoom,           {0} },
	{ MODKEY,                       XK_Tab,    view,           {0} },
	{ MODKEY|ShiftMask,             XK_c,      killclient,     {0} },
	{ MODKEY,                       XK_t,      setlayout,      {.v = &layouts[0]} },
	{ MODKEY,                       XK_f,      setlayout,      {.v = &layouts[1]} },
	{ MODKEY,                       XK_m,      setlayout,      {.v = &layouts[2]} },
	{ MODKEY,                       XK_space,  setlayout,      {0} },
	{ MODKEY|ShiftMask,             XK_space,  togglefloating, {0} },
	{ 0, XF86XK_MonBrightnessDown,  spawn,     {.v = dimmer } },
        { 0, XF86XK_MonBrightnessUp,    spawn,     {.v = brighter } },
	{ MODKEY,                       XK_0,      view,           {.ui = ~0 } },
	{ MODKEY|ShiftMask,             XK_0,      tag,            {.ui = ~0 } },
	{ MODKEY,                       XK_comma,  focusmon,       {.i = -1 } },
	{ MODKEY,                       XK_period, focusmon,       {.i = +1 } },
	{ MODKEY|ShiftMask,             XK_comma,  tagmon,         {.i = -1 } },
	{ MODKEY|ShiftMask,             XK_period, tagmon,         {.i = +1 } },
	{ MODKEY,                       XK_minus,  setgaps,        {.i = -1 } },
	{ MODKEY,                       XK_equal,  setgaps,        {.i = +1 } },
	{ MODKEY|ShiftMask,             XK_equal,  setgaps,        {.i = 0  } },
	{ MODKEY,			XK_q,      killclient,     {0} }, // kill program, window gets removed
	TAGKEYS(                        XK_1,                      0)
	TAGKEYS(                        XK_2,                      1)
	TAGKEYS(                        XK_3,                      2)
	TAGKEYS(                        XK_4,                      3)
	TAGKEYS(                        XK_5,                      4)
	TAGKEYS(                        XK_6,                      5)
	TAGKEYS(                        XK_7,                      6)
	TAGKEYS(                        XK_8,                      7)
	TAGKEYS(                        XK_9,                      8)
	{ MODKEY|ShiftMask,             XK_q,      quit,           {0} },


	    // you can use both XK_* or a hexadecmial code to define a key in the second column, find the hexadecmial code with xev (X11 only)
    { Mod1Mask|ControlMask,              XK_f,      spawn,          SHCMD("pcmanfm") },
    { Mod1Mask,				 XK_w,      spawn,          SHCMD("firefox") },
    { Mod1Mask,				 XK_t,      spawn,          SHCMD("telegram-desktop") },
    { Mod1Mask|ControlMask,              XK_t,      spawn,          SHCMD("thunderbird") },
    { Mod1Mask|ControlMask,              XK_n,      spawn,          SHCMD("notepadqq") },
    { Mod1Mask|ControlMask,              XK_q,      spawn,          SHCMD("qpdfview") },
    { Mod1Mask|ControlMask,              XK_c,      spawn,          SHCMD("chromium") },
    { MODKEY,       		         XK_w,      spawn,          SHCMD("brave") },
    { MODKEY,				 XK_c,	    spawn,	    SHCMD("code") }, //vs-code
    { MODKEY,				 XK_v,	    spawn,	    SHCMD("virt-manager") },  
    { ControlMask|ShiftMask,	         XK_n,      spawn,	    SHCMD("brave --incognito") }, //open private windows in the Brave browser
    { Mod1Mask,				 XK_b,	    spawn,	    SHCMD("blueman-manager")}, //open bluetooth manager
    {0,	                XF86XK_AudioRaiseVolume,    spawn,          {.v = upvol } }, //increase audio volume, you muse use PulseAudio for this to work / arrow up
    {0,		        XF86XK_AudioLowerVolume,    spawn,          {.v = downvol } }, //decrease audio-volume / arrow down
    {0,		        XF86XK_AudioMute,	    spawn,          {.v = mutevol } }, 
    {MODKEY,				 0xff56,    spawn,          SHCMD("shutdown now")},
    {MODKEY|ShiftMask,			 XK_w,	    spawn,	    SHCMD("/home/stryder/connect-wifi.sh") },		
    {MODKEY,				 0xff55,    spawn,	    SHCMD("reboot")},
    {0,		                         0xff61,      spawn,        SHCMD("/home/stryder/screenshot.sh")},
    {MODKEY|ShiftMask,			 XK_s,	    spawn,	    SHCMD("/home/stryder/screenshotsel.sh")},
    {ControlMask|Mod1Mask,               XK_s,      spawn,          SHCMD("steam")},
    {ControlMask|Mod1Mask|ShiftMask,     XK_l,      spawn,          SHCMD("libreoffice")}, 
    {ControlMask|Mod1Mask|ShiftMask,     XK_m,      spawn,          SHCMD("pactl set-source-mute alsa_input.usb-MICE_MICROPHONE_USB_MICROPHONE_201308-00.mono-fallback 1")}, 
    {ControlMask|Mod1Mask|ShiftMask,     XK_u,      spawn,          SHCMD("pactl set-source-mute alsa_input.usb-MICE_MICROPHONE_USB_MICROPHONE_201308-00.mono-fallback 0")},
	
    // here the keyboard-keys for the workspaces are defined, if you don't have a numpad-block then you could for example replace the hexadecimal codes with XK_0 to XK_9, take into account that in the C-language the first element in an array is indexed with a 0, so the 0 here corresponds to workspace 1 etcetera
    TAGKEYS(                  XK_1,          0)
    TAGKEYS(                  XK_2,          1)
    TAGKEYS(                  XK_3,          2)
    TAGKEYS(                  XK_4,          3)
    TAGKEYS(                  XK_5,          4)
    TAGKEYS(                  XK_6,          5)
    TAGKEYS(                  XK_7,          6)
    TAGKEYS(                  XK_8,          7)
    TAGKEYS(                  XK_9,          8)
    {MODKEY|ShiftMask,        XK_q,      quit,           {0} },
};

/* button definitions */
/* click can be ClkTagBar, ClkLtSymbol, ClkStatusText, ClkWinTitle, ClkClientWin, or ClkRootWin */
static const Button buttons[] = {
	/* click                event mask      button          function        argument */
	{ ClkLtSymbol,          0,              Button1,        setlayout,      {0} },
	{ ClkLtSymbol,          0,              Button3,        setlayout,      {.v = &layouts[2]} },
	{ ClkWinTitle,          0,              Button2,        zoom,           {0} },
	{ ClkStatusText,        0,              Button2,        spawn,          {.v = termcmd } },
	{ ClkClientWin,         MODKEY,         Button1,        movemouse,      {0} },
	{ ClkClientWin,         MODKEY,         Button2,        togglefloating, {0} },
	{ ClkClientWin,         MODKEY,         Button3,        resizemouse,    {0} },
	{ ClkTagBar,            0,              Button1,        view,           {0} },
	{ ClkTagBar,            0,              Button3,        toggleview,     {0} },
	{ ClkTagBar,            MODKEY,         Button1,        tag,            {0} },
	{ ClkTagBar,            MODKEY,         Button3,        toggletag,      {0} },
};

   

