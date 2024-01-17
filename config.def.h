/* See LICENSE file for copyright and license details. */

/* constants */
#define TERMINAL "st"

/* appearance */
static const unsigned int borderpx  = 1;        /* border pixel of windows */
static const unsigned int snap      = 32;       /* snap pixel */
static const unsigned int gappih    = 10;       /* horiz inner gap between windows */
static const unsigned int gappiv    = 10;       /* vert inner gap between windows */
static const unsigned int gappoh    = 10;       /* horiz outer gap between windows and screen edge */
static const unsigned int gappov    = 10;       /* vert outer gap between windows and screen edge */
static const int smartgaps          = 0;        /* 1 means no outer gap when there is only one window */
static const int showbar            = 1;        /* 0 means no bar */
static const int extrabarright      = 0;        /* 1 means extra bar text on right */
static const char statussep         = ';';      /* separator between status bars */
static const int topbar             = 1;        /* 0 means bottom bar */
static const int vertpad            = 10;       /* vertical padding of bar */
static const int sidepad            = 10;       /* horizontal padding of bar */
static const char *fonts[]          = {"CozetteVector:pixelsize=12:antialias=true:autohint=true"};  // "monospace:size=10";
static const char dmenufont[]       = "CozetteVector:pixelsize=12:antialias=true:autohint=true";  // "monospace:size=10"};
static const char col_gray1[]       = "#000000"; // bar background
static const char col_gray2[]       = "#444444"; // border norm
static const char col_gray3[]       = "#bbbbbb"; // text norm color
static const char col_gray4[]       = "#bbbbbb"; // text sel color
static const char col_cyan[]        = "#005577"; // border sel
static const char col_borderbar[]   = "#005577"; // bar border
static const char *colors[][3]      = {
	/*               fg         bg         border   */
	[SchemeNorm] = { col_gray3, col_gray1, col_gray2 },
	[SchemeSel]  = { col_gray4, col_cyan, col_cyan  },
};

/* tagging */
static const char *tags[] = { "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX" };

static const Rule rules[] = {
	/* xprop(1):
	 *	WM_CLASS(STRING) = instance, class
	 *	WM_NAME(STRING) = title
	 */
	/* class      instance    title       tags mask     isfloating   monitor */
	{ "Gimp",     NULL,       NULL,       0,            1,           -1 },
	{ "Firefox",  NULL,       NULL,       1 << 8,       0,           -1 },
};

/* layout(s) */
static const float mfact     = 0.55; /* factor of master area size [0.05..0.95] */
static const int nmaster     = 1;    /* number of clients in master area */
static const int resizehints = 1;    /* 1 means respect size hints in tiled resizals */
static const int lockfullscreen = 1; /* 1 will force focus on the fullscreen window */

static const Layout layouts[] = {
	/* symbol     arrange function */
	{ "[T]",      tile },    /* first entry is default */
	{ "[F]",      NULL },    /* no layout function means floating behavior */
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
static const char *dmenucmd[] = { "dmenu_run", "-m", dmenumon, "-fn", dmenufont, "-nb", col_gray1, "-nf", col_gray3, "-sb", col_cyan, "-sf", col_gray4, NULL };
static const char *termcmd[]  = { "st", "-e", "dvtm", NULL };

#include <X11/XF86keysym.h>

static Key keys[] = {
	/* modifier                     key							function    		argument */

	TAGKEYS(                        XK_1,						0)
	TAGKEYS(                        XK_2,						1)
	TAGKEYS(                        XK_3,						2)
	TAGKEYS(                        XK_4,						3)
	TAGKEYS(                        XK_5,						4)
	TAGKEYS(                        XK_6,						5)
	TAGKEYS(                        XK_7,						6)
	TAGKEYS(                        XK_8,						7)
	TAGKEYS(                        XK_9,						8)
	
	//{ MODKEY,                     XK_0,						view,       		{.ui = ~0 } },
	//{ MODKEY|ShiftMask,           XK_0,						tag,        		{.ui = ~0 } },
    //{ MODKEY,			            XK_minus,					spawn,				SHCMD("pamixer --allow-boost -d 5; kill -44 $(pidof dwmblocks)") },
    //{ MODKEY|ShiftMask,		    XK_minus,					spawn,				SHCMD("pamixer --allow-boost -d 15; kill -44 $(pidof dwmblocks)") },
    //{ MODKEY,			            XK_equal,					spawn,				SHCMD("pamixer --allow-boost -i 5; kill -44 $(pidof dwmblocks)") },
    //{ MODKEY|ShiftMask,		    XK_equal,					spawn,				SHCMD("pamixer --allow-boost -i 15; kill -44 $(pidof dwmblocks)") },
    //{ MODKEY,			            XK_BackSpace,				spawn,				SHCMD("sysact") },
    //{ MODKEY|ShiftMask,		    XK_BackSpace,				spawn,				SHCMD("sysact") },

	{ MODKEY,                       XK_Tab,						view,           	{0} },
	{ MODKEY|ShiftMask,             XK_q,						quit,           	{0} },
	{ MODKEY,			            XK_w,						killclient,	    	{0} },
	{ MODKEY,			            XK_r,						spawn,		    	SHCMD(TERMINAL " -e ranger") },
    { MODKEY|ShiftMask,		        XK_r,						spawn,		    	SHCMD(TERMINAL " -e htop") },
	{ MODKEY,                       XK_t,						setlayout,      	{.v = &layouts[0]} },
    //{ MODKEY,			            XK_y,						setlayout,	    	{.v = &layouts[2]} }, /* spiral */
    //{ MODKEY|ShiftMask,		    XK_y,						setlayout,	    	{.v = &layouts[3]} }, /* dwindle */
    { MODKEY,			            XK_u,						setlayout,      	{.v = &layouts[2]} }, // monocle
    //{ MODKEY,			            XK_u,						setlayout,	    	{.v = &layouts[4]} }, /* deck */
    //{ MODKEY|ShiftMask,		    XK_u,						setlayout,	    	{.v = &layouts[5]} }, /* monocle */
    { MODKEY,			            XK_i,						setlayout,      	{.v = &layouts[1]} }, // floating
    //{ MODKEY,			            XK_i,						setlayout,	    	{.v = &layouts[6]} }, /* centeredmaster */
    //{ MODKEY|ShiftMask,		    XK_i,						setlayout,	    	{.v = &layouts[7]} }, /* centeredfloatingmaster */
	{ MODKEY,			            XK_o,						incnmaster,     	{.i = +1 } },
	{ MODKEY|ShiftMask,		        XK_o,						incnmaster,     	{.i = -1 } },
    { MODKEY,                       XK_p,						spawn,          	{.v = dmenucmd } },

    //{ MODKEY,			            XK_bracketleft,				spawn,				SHCMD("mpc seek -10") },
    //{ MODKEY|ShiftMask,		    XK_bracketleft,				spawn,				SHCMD("mpc seek -60") },
    //{ MODKEY,			            XK_bracketright,			spawn,				SHCMD("mpc seek +10") },
    //{ MODKEY|ShiftMask,		    XK_bracketright,			spawn,				SHCMD("mpc seek +60") },
	{ MODKEY,                       XK_Return,					spawn,          	{.v = termcmd } },
	
    //{ MODKEY,			            XK_a,						togglegaps,	    	{0} },
    //{ MODKEY|ShiftMask,		    XK_a,						defaultgaps,		{0} },
    //{ MODKEY,			            XK_s,						togglesticky,		{0} },
    //{ MODKEY|ShiftMask,		    XK_s,						spawn,		    	SHCMD("") },
    //{ MODKEY,			            XK_d,						spawn,		    	SHCMD("") },
    //{ MODKEY|ShiftMask,		    XK_d,						spawn,		    	SHCMD("") },
    //{ MODKEY,			            XK_f,						togglefullscr,		{0} },
    //{ MODKEY|ShiftMask,		    XK_f,						setlayout,	    	{.v = &layouts[8]} },
    //{ MODKEY,			            XK_g,						shiftview,	    	{ .i = -1 } },
    { MODKEY,			            XK_g,						togglegaps,	    	{0} },
    { MODKEY|ShiftMask,		        XK_g,						defaultgaps,		{0} },
	{ MODKEY,			            XK_h,						setmfact,	    	{.f = -0.05} },
	{ MODKEY,                       XK_j,						focusstack,     	{.i = +1 } },
	{ MODKEY,                       XK_k,						focusstack,     	{.i = -1 } },
	{ MODKEY,			            XK_l,						setmfact,      		{.f = +0.05} },

	//todo, isso aqui faz o contrario do mod g	
	//{ MODKEY,						XK_semicolon,				shiftview,			{ .i = 1 } },
	//{ MODKEY|ShiftMask,			XK_semicolon,				shifttag,			{ .i = 1 } },
	//{ MODKEY,						XK_apostrophe,				togglescratch,		{.ui = 1} },
	//{ MODKEY|ShiftMask,			XK_apostrophe,				spawn,				SHCMD("") },

	//{ MODKEY,						XK_z,						incrgaps,			{.i = +3 } },
	//{ MODKEY|ShiftMask,			XK_z,						spawn,				SHCMD("") },
	//{ MODKEY,						XK_x,						incrgaps,			{.i = -3 } },
	//{ MODKEY|ShiftMask,			XK_x,						spawn,				SHCMD("") }, */
	//{ MODKEY,						XK_c,						spawn,				SHCMD("") }, */
	//{ MODKEY|ShiftMask,			XK_c,						spawn,				SHCMD("") }, */

	//	/* V is automatically bound above in STACKKEYS */
	{ MODKEY,						XK_b,						togglebar,			{0} },
	//{ MODKEY|ShiftMask,			XK_b,						spawn,				SHCMD("") }, */
	{ MODKEY,						XK_n,						spawn,				SHCMD("brave") },
	//{ MODKEY|ShiftMask,			XK_n,						spawn,				SHCMD(TERMINAL " -e newsboat; pkill -RTMIN+6 dwmblocks") },
	//{ MODKEY,						XK_m,						spawn,				SHCMD(TERMINAL " -e ncmpcpp") },
	//{ MODKEY|ShiftMask,			XK_m,						spawn,				SHCMD("pamixer -t; kill -44 $(pidof dwmblocks)") },
	//{ MODKEY,						XK_comma,					spawn,				SHCMD("mpc prev") },
	//{ MODKEY|ShiftMask,			XK_comma,					spawn,				SHCMD("mpc seek 0%") },
	//{ MODKEY,						XK_period,					spawn,				SHCMD("mpc next") },
	//{ MODKEY|ShiftMask,			XK_period,					spawn,				SHCMD("mpc repeat") },

	{ MODKEY,                       XK_space,					zoom,      			{0} },
	{ MODKEY|ShiftMask,             XK_space,					togglefloating, 	{0} },

	//{ MODKEY,                     XK_comma,					focusmon,      		{.i = -1 } },
	//{ MODKEY,                     XK_period,					focusmon,      		{.i = +1 } },
	//{ MODKEY|ShiftMask,           XK_comma,					tagmon,        		{.i = -1 } },
	//{ MODKEY|ShiftMask,           XK_period,					tagmon,        		{.i = +1 } },

	{ MODKEY,						XK_Left,					focusmon,			{.i = -1 } },
	{ MODKEY|ShiftMask,				XK_Left,					tagmon,				{.i = -1 } },
	{ MODKEY,						XK_Right,					focusmon,			{.i = +1 } },
	{ MODKEY|ShiftMask,				XK_Right,					tagmon,				{.i = +1 } },

	//{ MODKEY,						XK_Page_Up,					shiftview,			{ .i = -1 } },
	//{ MODKEY|ShiftMask,			XK_Page_Up,					shifttag,			{ .i = -1 } },
	//{ MODKEY,						XK_Page_Down,				shiftview,			{ .i = +1 } },
	//{ MODKEY|ShiftMask,			XK_Page_Down,				shifttag,			{ .i = +1 } },
	//{ MODKEY,						XK_Insert,					spawn,				SHCMD("") },

	{ MODKEY,            			XK_Escape,					spawn,				SHCMD("slock & xset dpms force off; mpc pause; pauseallmpv") },
	{ 0,                            XK_Print,					spawn,          	SHCMD("scrot -f -s -q 100 -e 'xclip -selection clipboard -target image/png -i $f && rm $f'") },
	{ MODKEY,						XK_Print,					spawn,				SHCMD("scrot -f -q 100 -e 'xclip -selection clipboard -target image/png -i $f && rm $f'") },
	//{ MODKEY,						XK_Print,					spawn,				SHCMD("dmenurecord") },
	//{ MODKEY|ShiftMask,			XK_Print,					spawn,				SHCMD("dmenurecord kill") },
	//{ MODKEY,						XK_Delete,					spawn,				SHCMD("dmenurecord kill") },
	//{ MODKEY,						XK_Scroll_Lock,				spawn,				SHCMD("killall screenkey || screenkey &") },	

	{ 0, 							XF86XK_AudioMute,			spawn,      	    SHCMD("amixer -D pulse sset Master toggle && kill -30 $(cat $HOME/.cache/barpid)") },
	{ 0, 							XF86XK_AudioLowerVolume,	spawn,         		SHCMD("amixer -D pulse sset Master 5%- && kill -30 $(cat $HOME/.cache/barpid)") },
	{ 0, 							XF86XK_AudioRaiseVolume,	spawn,          	SHCMD("amixer -D pulse sset Master 5%+ && kill -30 $(cat $HOME/.cache/barpid)") },
	
	{ MODKEY, 						XF86XK_AudioMute,			spawn,          	SHCMD("~/.scripts/sp play") },
	{ MODKEY, 						XF86XK_AudioLowerVolume,	spawn,          	SHCMD("~/.scripts/sp prev") },
	{ MODKEY, 						XF86XK_AudioRaiseVolume,	spawn,          	SHCMD("~/.scripts/sp next") },

	//{ 0, 							XF86XK_AudioStop,			spawn,				SHCMD("mpc stop") },
	//{ 0, 							XF86XK_AudioRewind,			spawn,				SHCMD("mpc seek -10") },
	//{ 0, 							XF86XK_AudioForward,		spawn,				SHCMD("mpc seek +10") },
	//{ 0, 							XF86XK_AudioMedia,			spawn,				SHCMD(TERMINAL " -e ncmpcpp") },
	//{ 0, 							XF86XK_AudioMicMute,		spawn,				SHCMD("pactl set-source-mute @DEFAULT_SOURCE@ toggle") },
	//{ 0, 							XF86XK_TouchpadToggle,		spawn,				SHCMD("(synclient | grep 'TouchpadOff.*1' && synclient TouchpadOff=0) || synclient TouchpadOff=1") },
	//{ 0, 							XF86XK_TouchpadOff,			spawn,				SHCMD("synclient TouchpadOff=1") },
	//{ 0, 							XF86XK_TouchpadOn,			spawn,				SHCMD("synclient TouchpadOff=0") },
	{ 0, 							XF86XK_MonBrightnessUp,		spawn,				SHCMD("xbacklight -inc 10 && kill -30 $(cat $HOME/.cache/barpid)") },
	{ 0, 							XF86XK_MonBrightnessDown,	spawn,				SHCMD("xbacklight -dec 10 && kill -30 $(cat $HOME/.cache/barpid)") },

	/* { MODKEY|Mod4Mask,              XK_h,      incrgaps,       {.i = +1 } }, */
	/* { MODKEY|Mod4Mask,              XK_l,      incrgaps,       {.i = -1 } }, */
	/* { MODKEY|Mod4Mask|ShiftMask,    XK_h,      incrogaps,      {.i = +1 } }, */
	/* { MODKEY|Mod4Mask|ShiftMask,    XK_l,      incrogaps,      {.i = -1 } }, */
	/* { MODKEY|Mod4Mask|ControlMask,  XK_h,      incrigaps,      {.i = +1 } }, */
	/* { MODKEY|Mod4Mask|ControlMask,  XK_l,      incrigaps,      {.i = -1 } }, */
	/* { MODKEY|Mod4Mask|ShiftMask,    XK_0,      defaultgaps,    {0} }, */
	/* { MODKEY,                       XK_y,      incrihgaps,     {.i = +1 } }, */
	/* { MODKEY,                       XK_o,      incrihgaps,     {.i = -1 } }, */
	/* { MODKEY|ControlMask,           XK_y,      incrivgaps,     {.i = +1 } }, */
	/* { MODKEY|ControlMask,           XK_o,      incrivgaps,     {.i = -1 } }, */
	/* { MODKEY|Mod4Mask,              XK_y,      incrohgaps,     {.i = +1 } }, */
	/* { MODKEY|Mod4Mask,              XK_o,      incrohgaps,     {.i = -1 } }, */
	/* { MODKEY|ShiftMask,             XK_y,      incrovgaps,     {.i = +1 } }, */
	/* { MODKEY|ShiftMask,             XK_o,      incrovgaps,     {.i = -1 } }, */

};

/* button definitions */
/* click can be ClkTagBar, ClkLtSymbol, ClkStatusText, ClkWinTitle, ClkClientWin, or ClkRootWin */
static Button buttons[] = {
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

/*#ifndef __OpenBSD__
	{ ClkWinTitle,          0,              Button2,        zoom,           {0} },
	{ ClkStatusText,        0,              Button1,        sigdwmblocks,   {.i = 1} },
	{ ClkStatusText,        0,              Button2,        sigdwmblocks,   {.i = 2} },
	{ ClkStatusText,        0,              Button3,        sigdwmblocks,   {.i = 3} },
	{ ClkStatusText,        0,              Button4,        sigdwmblocks,   {.i = 4} },
	{ ClkStatusText,        0,              Button5,        sigdwmblocks,   {.i = 5} },
	{ ClkStatusText,        ShiftMask,      Button1,        sigdwmblocks,   {.i = 6} },
#endif
	{ ClkStatusText,        ShiftMask,      Button3,        spawn,          SHCMD(TERMINAL " -e nvim ~/.local/src/dwmblocks/config.h") },
	{ ClkClientWin,         MODKEY,         Button1,        movemouse,      {0} },
	{ ClkClientWin,         MODKEY,         Button2,        defaultgaps,	{0} },
	{ ClkClientWin,         MODKEY,         Button3,        resizemouse,    {0} },
	{ ClkClientWin,		MODKEY,		Button4,	incrgaps,	{.i = +1} },
	{ ClkClientWin,		MODKEY,		Button5,	incrgaps,	{.i = -1} },
	{ ClkTagBar,            0,              Button1,        view,           {0} },
	{ ClkTagBar,            0,              Button3,        toggleview,     {0} },
	{ ClkTagBar,            MODKEY,         Button1,        tag,            {0} },
	{ ClkTagBar,            MODKEY,         Button3,        toggletag,      {0} },
	{ ClkTagBar,		0,		Button4,	shiftview,	{.i = -1} },
	{ ClkTagBar,		0,		Button5,	shiftview,	{.i = 1} },
	{ ClkRootWin,		0,		Button2,	togglebar,	{0} },*/
};

