/* See LICENSE file for copyright and license details. */

/* autostart */
static const char *const autostart[] = {
/*	"xrandr", "--output", "DP-0", "--mode", "3440x1440", NULL, */
	"pipewire", NULL,
	"feh", "--bg-center", "/home/andi/Pictures/rose_pine_ship.png", NULL,
	"picom", NULL,
	NULL
};

/* appearance */
static const unsigned int borderpx  = 2;        /* border pixel of windows */
static const unsigned int gappx	    = 10;
static const unsigned int snap      = 32;       /* snap pixel */
static const int showbar            = 1;        /* 0 means no bar */
static const int topbar             = 1;        /* 0 means bottom bar */
static const double defaultopacity  = 0.75;
static const char *fonts[]          = { "JetBrainsMono Nerd Font:size=10" };
static const char dmenufont[]       = "JetBrainsMono Nerd Font:size=10";

static const char col_base[]			= "#232136";
static const char col_surface[]			= "#2a273f";
static const char col_overlay[]			= "#393552";
static const char col_muted[]			= "#6e6a86";
static const char col_subtle[]			= "#908caa";
static const char col_text[]			= "#e0def4";
static const char col_love[]			= "#eb6f92";
static const char col_gold[]			= "#f6c177";
static const char col_rose[]			= "#ea9a97";
static const char col_pine[]			= "#3e8fb0";
static const char col_foam[]			= "#9ccfd8";
static const char col_iris[]			= "#c4a7e7";
static const char col_highlight_low[]		= "#2a283e";
static const char col_highlight_med[]		= "#44415a";
static const char col_highlight_high[]		= "#56526e";

static const unsigned int baralpha = 0x50;
static const unsigned int borderalpha = OPAQUE;

static const char *colors[][3]      = {
	/*               fg         	bg         		border   */
	[SchemeNorm] = { col_muted, 	col_base, 		col_muted },
	[SchemeSel]  = { col_text, 	col_love, 	 	col_love  },
};

static const unsigned int alphas[][3]      = {
        /*               fg      bg        border*/
        [SchemeNorm] = { OPAQUE, baralpha, borderalpha },
	[SchemeSel]  = { OPAQUE, baralpha, borderalpha },
};

/* tagging */
static const char *tags[] = { "1", "2", "3", "4", "5", "6", "7", "8", "9" };

static const Rule rules[] = {
	/* xprop(1):
	 *	WM_CLASS(STRING) = instance, class
	 *	WM_NAME(STRING) = title
	 */
	/* class      		instance    title       tags mask     isfloating   monitor */
	{ "pavucontrol",	NULL,       NULL,       0,            1,           -1 },
};

/* layout(s) */
static const float mfact     = 0.55; /* factor of master area size [0.05..0.95] */
static const int nmaster     = 1;    /* number of clients in master area */
static const int resizehints = 1;    /* 1 means respect size hints in tiled resizals */
static const int lockfullscreen = 1; /* 1 will force focus on the fullscreen window */

static const Layout layouts[] = {
	/* symbol     arrange function */
	{ "[]=",      tile },    /* first entry is default */
	{ "><>",      NULL },    /* no layout function means floating behavior */
	{ "[M]",      monocle },
};

/* key definitions */
#define MODKEY Mod4Mask
#define TAGKEYS(KEY,TAG) \
	{ MODKEY,                       KEY,      view,           {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask,           KEY,      toggleview,     {.ui = 1 << TAG} }, \
	{ MODKEY|ShiftMask,             KEY,      tag,            {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask|ShiftMask, KEY,      toggletag,      {.ui = 1 << TAG} },

/* helper for spawning shell commands in the pre dwm-5.0 fashion */
#define SHCMD(cmd) { .v = (const char*[]){ "/bin/sh", "-c", cmd, NULL } }

/* commands */
static char dmenumon[2] = "0"; /* component of dmenucmd, manipulated in spawn() */
static const char *dmenucmd[] = { "dmenu_run", "-m", dmenumon, "-fn", dmenufont, "-nb", col_base, "-nf", col_muted, "-sb", col_love, "-sf", col_text, NULL };
static const char *termcmd[]  		= { "wezterm", NULL };
static const char *browsercmd[] 	= {"firefox", NULL};
static const char *filebrowsercmd[]	= {"thunar", NULL};
static const char *setopaquecmd[]	= {"transset", "-p", "1", NULL};
static const char *settransparentcmd[]	= {"transset", "-p", "0.75", NULL};

static const char *umlaut_o[]		= {"xdotool", "key", "U00F6", NULL};

static const Key keys[] = {
	/* modifier                     key        function        		argument */
	{ MODKEY|ShiftMask,             XK_Return, 	spawn,          	{.v = dmenucmd } },
	{ MODKEY,                       XK_Return, 	spawn,          	{.v = termcmd } },
	{ MODKEY,                       XK_b,      	spawn,          	{.v = browsercmd } },
	{ MODKEY,			XK_e,		spawn,			{.v = filebrowsercmd } },
	{ MODKEY|ShiftMask, 		XK_o,		spawn,			{.v = setopaquecmd } },
	{ MODKEY, 			XK_o,		spawn,			{.v = settransparentcmd } },
	{ MODKEY,                       XK_j,      	focusstack,     	{.i = -1 } },
	{ MODKEY,                       XK_l,     	focusstack,     	{.i = +1 } },
	{ MODKEY,                       XK_i,      	focusstack,     	{.i = -1 } },
	{ MODKEY,                       XK_k,      	focusstack,     	{.i = +1 } },
	{ MODKEY|ShiftMask,             XK_j,     	incnmaster,     	{.i = +1 } },
	{ MODKEY|ShiftMask,             XK_l,      	incnmaster,     	{.i = -1 } },
/*	{ MODKEY,                       XK_h,      	setmfact,       	{.f = -0.05} },
	{ MODKEY,                       XK_l,      	setmfact,       	{.f = +0.05} }, */
	{ MODKEY,                       XK_z,      	zoom,           	{0} },
	{ MODKEY,                       XK_Tab,    	view,           	{0} },
	{ MODKEY,                       XK_q,      	killclient,     	{0} },
	{ MODKEY,                       XK_t,      	setlayout,      	{.v = &layouts[0]} },
	{ MODKEY,                       XK_m,      	setlayout,      	{.v = &layouts[2]} },
	{ MODKEY,                       XK_f,      	togglefullscreen,	{0} },
	{ MODKEY,                       XK_space,  	setlayout,      	{0} },
	{ MODKEY|ShiftMask,             XK_space,  	togglefloating, 	{0} },
	{ MODKEY,                       XK_0,      	view,           	{.ui = ~0 } },
	{ MODKEY|ShiftMask,             XK_0,      	tag,            	{.ui = ~0 } },
	{ MODKEY,                       XK_comma,  	focusmon,       	{.i = -1 } },
	{ MODKEY,                       XK_period, 	focusmon,       	{.i = +1 } },
	{ MODKEY|ShiftMask,             XK_comma,  	tagmon,         	{.i = -1 } },
	{ MODKEY|ShiftMask,             XK_period, 	tagmon,         	{.i = +1 } },

	{ Mod1Mask,			XK_o,		spawn,			{.v =  umlaut_o } },

	TAGKEYS(                        XK_1,      	                	0)
	TAGKEYS(                        XK_2,      	                	1)
	TAGKEYS(                        XK_3,      	                	2)
	TAGKEYS(                        XK_4,      	                	3)
	TAGKEYS(                        XK_5,      	                	4)
	TAGKEYS(                        XK_6,      	                	5)
	TAGKEYS(                        XK_7,      	                	6)
	TAGKEYS(                        XK_8,      	                	7)
	TAGKEYS(                        XK_9,      	                	8)
	{ MODKEY|ShiftMask,             XK_e,      	quit,           	{0} },
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

