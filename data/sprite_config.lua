--[[ 
	Dostepne metody:
		cxx_addSprite( string name, int width, int height, int atlas_pos_x, int atlas_pos_y, 
					   int level, float frame_time, int frame count, bool loop 
					  );
--]]

TIME_FACTOR = 2

--		NAME            		 width   	height  	X     		 Y    	  level  	frame time      count     loop
cxx_addSprite( "NEW_GAME",        215,  	 220,   	1220,  	  	10,     	1,         1000 ,    	  1,     false );

cxx_addSprite( "PLAYER_RUN",      50,   	 98,    	1,     		120,    	1,         40 ,    	      10,    true  );

cxx_addSprite( "PLAYER_STAND",    50,   	 98,     	551,   		120,    	1,         100 ,    	  1,     false );

cxx_addSprite( "PLAYER_FLY",      52,   	 100,   	600,    	122,    	1,         60 ,     	  1,     true  );

cxx_addSprite( "COUNTING",        75,   	 100,    	2,      	340,      	1,         400,    	      3,     false );

cxx_addSprite( "LIVE_BAR",        100,  	 64,   	    858,    	39,     	1,         620 ,    	  1,     false );

cxx_addSprite( "LIVE_BAR_BACK",   200,  	 27,   	    1000,    	54,       	1,         620 ,    	  1,     false );

cxx_addSprite( "LIVE_BAR_FILL",   200,  	 33,   	    1000,    	20,       	1,         620 ,    	  1,     false );


-- Zestaw icon: "hand drawn web icon set"
cxx_addSprite( "DIALOG",   		  80,  	  	 80,   	    411,    	385,       	1,         0 ,    	      1,     false );
cxx_addSprite( "STAR_HALF",   	  80,  	  	 80,   	    411,    	280,       	1,         0 ,    	      1,     false );
cxx_addSprite( "STAR_MULTI",   	  80,  	  	 80,   	    572,    	280,       	1,         0 ,    	      1,     false );
cxx_addSprite( "ADD",   	      80,  	  	 80,   	    500,    	280,       	1,         0 ,    	      1,     false );
cxx_addSprite( "DIALOG_DRAW",     80,  	  	 80,   	    660,    	290,       	1,         0 ,    	      1,     false );
cxx_addSprite( "INFO",            80,  	  	 80,   	    738,    	290,       	1,         0 ,    	      1,     false );
cxx_addSprite( "EMPTY",           80,  	  	 80,   	    815,    	290,       	1,         0 ,    	      1,     false );
cxx_addSprite( "HEARTH_WARRING",  80,  	  	 80,   	    229,    	381,       	1,         0 ,    	      1,     false );
cxx_addSprite( "HEARTH_ADD",      80,  	  	 80,   	    333,    	381,       	1,         0 ,    	      1,     false );
cxx_addSprite( "WARNING",        80,  	  	 80,   	    492,    	381,       	1,         0 ,    	      1,     false );
cxx_addSprite( "HEARTH_MULTI",    80,  	  	 80,   	    565,    	381,       	1,         0 ,    	      1,     false );
cxx_addSprite( "PENCIL",          80,  	  	 80,   	    652,    	381,       	1,         0 ,    	      1,     false );
cxx_addSprite( "CLOSE",           80,  	  	 80,   	    740,    	381,       	1,         0 ,    	      1,     false );
cxx_addSprite( "STAR",            80,  	  	 80,   	    815,    	381,       	1,         0 ,    	      1,     false );


-- Konfiguracja fragmentow mapy
map_ground_y = 60; 
map_size_1 = 50;
map_meteo_y = 237;


cxx_addSprite( "MAP_0",        25,     25,    10,  60,     1, 1000, 1, false );
cxx_addSprite( "MAP_1",  map_size_1,     map_size_1,       3 * map_size_1,  map_meteo_y + map_size_1,  1, 1000, 1, false );
cxx_addSprite( "MAP_2",  map_size_1,     map_size_1,       2 * map_size_1,  map_meteo_y + map_size_1,  1, 1000, 1, false );
cxx_addSprite( "MAP_3",  map_size_1,     map_size_1,       1 * map_size_1,  map_meteo_y + map_size_1,  1, 1000, 1, false );

cxx_addSprite( "MAP_4",  map_size_1,     map_size_1,       0 * map_size_1,   map_meteo_y + map_size_1,  1, 1000, 1, false );
cxx_addSprite( "MAP_5",  map_size_1,     map_size_1,       15 * map_size_1,  map_meteo_y,     1, 1000, 1, false );
cxx_addSprite( "MAP_6",  map_size_1,     map_size_1,       14 * map_size_1,  map_meteo_y,     1, 1000, 1, false );
cxx_addSprite( "MAP_7",  map_size_1,     map_size_1,       13 * map_size_1,  map_meteo_y,     1, 1000, 1, false );
cxx_addSprite( "MAP_8",  map_size_1,     map_size_1,       12 * map_size_1,  map_meteo_y,     1, 1000, 1, false );
cxx_addSprite( "MAP_9",  map_size_1,     map_size_1,       11 * map_size_1,  map_meteo_y,     1, 1000, 1, false );

cxx_addSprite( "MAP_10",  map_size_1,     map_size_1,      10 * map_size_1,  map_meteo_y,     1, 1000, 1, false );
cxx_addSprite( "MAP_11",  map_size_1,     map_size_1,      9 * map_size_1,  map_meteo_y,     1, 1000, 1, false );
cxx_addSprite( "MAP_12",  map_size_1,     map_size_1,      8 * map_size_1,  map_meteo_y,     1, 1000, 1, false );
cxx_addSprite( "MAP_13",  map_size_1,     map_size_1,      7 * map_size_1,  map_meteo_y,     1, 1000, 1, false );
cxx_addSprite( "MAP_14",  map_size_1,     map_size_1,      6 * map_size_1,  map_meteo_y,     1, 1000, 1, false );

cxx_addSprite( "MAP_15",  map_size_1,     map_size_1,      5 * map_size_1,  map_meteo_y,     1, 1000, 1, false );
cxx_addSprite( "MAP_16",  map_size_1,     map_size_1,      4 * map_size_1,  map_meteo_y,     1, 1000, 1, false );
cxx_addSprite( "MAP_17",  map_size_1,     map_size_1,      3 * map_size_1,  map_meteo_y,     1, 1000, 1, false );
cxx_addSprite( "MAP_18",  map_size_1,     map_size_1,      2 * map_size_1,  map_meteo_y,     1, 1000, 1, false );
cxx_addSprite( "MAP_19",  map_size_1,     map_size_1,      1 * map_size_1,  map_meteo_y,     1, 1000, 1, false );
cxx_addSprite( "MAP_20",  map_size_1,     map_size_1,      0,     	       map_meteo_y,     1, 1000, 1, false );

cxx_addSprite( "MAP_21",  map_size_1,     map_size_1,   15 * map_size_1-1,  map_ground_y,     1, 1000, 1, false );
cxx_addSprite( "MAP_22",  map_size_1,     map_size_1,   14 * map_size_1,    map_ground_y,     1, 1000, 1, false );
cxx_addSprite( "MAP_23",  map_size_1,     map_size_1,   13 * map_size_1,    map_ground_y,     1, 1000, 1, false );
cxx_addSprite( "MAP_24",  map_size_1,     map_size_1,   12 * map_size_1,    map_ground_y,     1, 1000, 1, false );

cxx_addSprite( "MAP_25",  map_size_1,     map_size_1,   11 * map_size_1,    map_ground_y,     1, 1000, 1, false );
cxx_addSprite( "MAP_26",  map_size_1,     map_size_1,   10 * map_size_1,    map_ground_y,     1, 1000, 1, false );
cxx_addSprite( "MAP_27",  map_size_1,     map_size_1,    9 * map_size_1,    map_ground_y,     1, 1000, 1, false );
cxx_addSprite( "MAP_28",  map_size_1,     map_size_1,    8 * map_size_1,    map_ground_y,     1, 1000, 1, false );
cxx_addSprite( "MAP_29",  map_size_1,     map_size_1,    7 * map_size_1,    map_ground_y,     1, 1000, 1, false );
cxx_addSprite( "MAP_30",  map_size_1,     map_size_1,    6 * map_size_1,    map_ground_y,     1, 1000, 1, false );

cxx_addSprite( "MAP_31",  map_size_1,     map_size_1,    5 * map_size_1,    map_ground_y,     1, 1000, 1, false );
cxx_addSprite( "MAP_32",  map_size_1,     map_size_1,    4 * map_size_1,    map_ground_y,     1, 1000, 1, false );
cxx_addSprite( "MAP_33",  map_size_1,     map_size_1,    3 * map_size_1,    map_ground_y,     1, 1000, 1, false );
cxx_addSprite( "MAP_34",  map_size_1,     map_size_1,    2 * map_size_1,    map_ground_y,     1, 1000, 1, false );
cxx_addSprite( "MAP_35",  map_size_1,     map_size_1,    1 * map_size_1,    map_ground_y,     1, 1000, 1, false );
cxx_addSprite( "MAP_36",  map_size_1,     map_size_1,    0,                 map_ground_y,     1, 1000, 1, false );

-- babelki
cxx_addSprite( "MAP_37",  map_size_1,     map_size_1,    -2+(5 * map_size_1),    (map_meteo_y + map_size_1),  1, 1000, 1, false );
cxx_addSprite( "MAP_38",  map_size_1,     map_size_1,    -2+(6 * map_size_1),     map_meteo_y + map_size_1,  1, 1000, 1, false );

-- platformy
cxx_addSprite( "MAP_39",  map_size_1,     map_size_1,    0,                 0,                    1, 1000, 1, false );

--enemy (nie wykorzystywany)
cxx_addSprite( "MAP_40",  map_size_1,     map_size_1,    0,               460,                    1, 1000, 1, false );

--aditional bonus
cxx_addSprite( "MAP_41",  map_size_1,  	  	 map_size_1, 585,    	395,       	1,         0 ,    	      1,     false );

print( "[ Lua ] End of script:sprite_config.lua" );


-- monster 1 left,right,stand
monster1_y = 458;
monster_size = 50;
cxx_addSprite( "M1_L",  monster_size,     monster_size,    200,               monster1_y,                    1, 1000, 1, false );
cxx_addSprite( "M1_R",  monster_size,     monster_size,    100,               monster1_y,                    1, 1000, 1, false );
cxx_addSprite( "M1_S",  monster_size,     monster_size,    0,                 monster1_y,                    1, 1000, 1, false );










