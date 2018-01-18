const int16_t wavetable[]={
0,
754,
1507,
2258,
3005,
3749,
4486,
5218,
5941,
6656,
7361,
8055,
8738,
9408,
10065,
10707,
11334,
11944,
12538,
13114,
13672,
14210,
14729,
15227,
15705,
16161,
16595,
17006,
17396,
17762,
18105,
18424,
18720,
18991,
19239,
19464,
19664,
19840,
19993,
20122,
20228,
20311,
20372,
20410,
20425,
20420,
20394,
20347,
20280,
20194,
20089,
19966,
19826,
19670,
19497,
19310,
19109,
18895,
18668,
18429,
18181,
17922,
17655,
17380,
17098,
16810,
16517,
16221,
15921,
15620,
15317,
15014,
14712,
14412,
14114,
13820,
13530,
13245,
12966,
12695,
12430,
12174,
11927,
11690,
11463,
11247,
11042,
10849,
10669,
10502,
10348,
10208,
10082,
9970,
9873,
9791,
9723,
9671,
9633,
9610,
9603,
9610,
9632,
9669,
9720,
9785,
9864,
9957,
10062,
10180,
10311,
10453,
10606,
10770,
10944,
11128,
11320,
11520,
11727,
11941,
12161,
12386,
12615,
12848,
13083,
13320,
13558,
13797,
14034,
14270,
14503,
14734,
14960,
15181,
15396,
15605,
15806,
15999,
16184,
16358,
16522,
16675,
16816,
16945,
17061,
17163,
17251,
17324,
17382,
17424,
17451,
17460,
17454,
17430,
17389,
17330,
17254,
17160,
17048,
16919,
16772,
16607,
16425,
16225,
16008,
15774,
15523,
15257,
14974,
14676,
14363,
14035,
13694,
13339,
12971,
12592,
12201,
11799,
11388,
10967,
10539,
10103,
9660,
9212,
8759,
8302,
7843,
7381,
6919,
6457,
5995,
5536,
5080,
4627,
4180,
3738,
3303,
2877,
2458,
2050,
1652,
1266,
892,
532,
185,
-146,
-462,
-762,
-1045,
-1310,
-1556,
-1784,
-1993,
-2181,
-2349,
-2496,
-2622,
-2726,
-2809,
-2869,
-2907,
-2923,
-2916,
-2886,
-2834,
-2760,
-2663,
-2544,
-2403,
-2240,
-2056,
-1850,
-1624,
-1378,
-1112,
-826,
-522,
-200,
138,
495,
867,
1254,
1655,
2071,
2498,
2938,
3388,
3848,
4317,
4794,
5278,
5768,
6262,
6760,
7261,
7764,
8267,
8769,
9270,
9768,
10262,
10752,
11236,
11712,
12181,
12641,
13091,
13530,
13957,
14372,
14773,
15159,
15530,
15885,
16223,
16543,
16845,
17129,
17392,
17636,
17859,
18061,
18242,
18400,
18537,
18651,
18742,
18811,
18856,
18879,
18878,
18854,
18807,
18738,
18645,
18530,
18393,
18233,
18052,
17850,
17627,
17384,
17121,
16839,
16538,
16219,
15883,
15531,
15163,
14779,
14382,
13971,
13547,
13112,
12667,
12211,
11747,
11274,
10795,
10309,
9819,
9325,
8827,
8328,
7827,
7326,
6826,
6328,
5833,
5341,
4854,
4373,
3898,
3430,
2970,
2519,
2078,
1647,
1227,
819,
424,
41,
-327,
-681,
-1021,
-1346,
-1655,
-1949,
-2226,
-2487,
-2731,
-2958,
-3168,
-3361,
-3536,
-3695,
-3836,
-3960,
-4067,
-4157,
-4231,
-4288,
-4330,
-4355,
-4366,
-4361,
-4342,
-4309,
-4263,
-4204,
-4133,
-4050,
-3956,
-3852,
-3738,
-3616,
-3485,
-3348,
-3203,
-3053,
-2899,
-2740,
-2578,
-2414,
-2248,
-2081,
-1915,
-1750,
-1586,
-1426,
-1269,
-1116,
-968,
-826,
-691,
-564,
-444,
-334,
-233,
-142,
-62,
6,
63,
108,
139,
158,
162,
153,
129,
91,
37,
-30,
-114,
-213,
-328,
-458,
-603,
-764,
-940,
-1131,
-1336,
-1556,
-1791,
-2039,
-2301,
-2576,
-2864,
-3163,
-3475,
-3797,
-4129,
-4471,
-4823,
-5182,
-5549,
-5922,
-6302,
-6686,
-7075,
-7467,
-7862,
-8258,
-8655,
-9051,
-9446,
-9839,
-10228,
-10614,
-10994,
-11368,
-11735,
-12094,
-12444,
-12784,
-13113,
-13431,
-13736,
-14027,
-14305,
-14567,
-14813,
-15042,
-15254,
-15448,
-15623,
-15778,
-15914,
-16029,
-16123,
-16195,
-16245,
-16273,
-16278,
-16260,
-16219,
-16154,
-16066,
-15954,
-15818,
-15658,
-15475,
-15267,
-15037,
-14783,
-14506,
-14206,
-13884,
-13539,
-13173,
-12786,
-12379,
-11951,
-11504,
-11038,
-10554,
-10053,
-9535,
-9001,
-8453,
-7890,
-7315,
-6727,
-6128,
-5519,
-4900,
-4274,
-3640,
-3000,
-2355,
-1707,
-1055,
-402,
251,
904,
1556,
2205,
2851,
3491,
4125,
4753,
5372,
5982,
6583,
7172,
7749,
8313,
8863,
9398,
9918,
10421,
10907,
11375,
11825,
12255,
12665,
13055,
13423,
13770,
14096,
14398,
14678,
14936,
15170,
15380,
15567,
15730,
15870,
15985,
16078,
16146,
16191,
16213,
16212,
16188,
16142,
16074,
15985,
15874,
15743,
15592,
15421,
15232,
15025,
14800,
14558,
14301,
14028,
13742,
13441,
13129,
12804,
12469,
12123,
11769,
11407,
11038,
10662,
10282,
9897,
9509,
9119,
8727,
8335,
7944,
7554,
7167,
6783,
6403,
6028,
5659,
5296,
4942,
4595,
4257,
3929,
3611,
3304,
3008,
2725,
2454,
2196,
1952,
1721,
1504,
1302,
1115,
943,
785,
643,
517,
405,
309,
228,
163,
112,
76,
55,
48,
55,
75,
109,
156,
215,
285,
367,
460,
562,
674,
795,
924,
1060,
1202,
1351,
1504,
1662,
1823,
1986,
2152,
2318,
2484,
2650,
2814,
2976,
3134,
3288,
3437,
3580,
3717,
3846,
3967,
4079,
4182,
4274,
4355,
4425,
4482,
4526,
4556,
4573,
4575,
4562,
4534,
4490,
4429,
4353,
4259,
4149,
4022,
3877,
3715,
3536,
3340,
3126,
2895,
2647,
2383,
2101,
1804,
1490,
1161,
817,
458,
84,
-302,
-702,
-1114,
-1539,
-1975,
-2421,
-2876,
-3341,
-3814,
-4294,
-4781,
-5273,
-5770,
-6270,
-6773,
-7278,
-7784,
-8290,
-8795,
-9298,
-9797,
-10293,
-10783,
-11268,
-11746,
-12215,
-12676,
-13127,
-13567,
-13996,
-14412,
-14814,
-15203,
-15576,
-15934,
-16274,
-16598,
-16904,
-17191,
-17458,
-17706,
-17934,
-18141,
-18326,
-18490,
-18632,
-18751,
-18848,
-18922,
-18973,
-19001,
-19005,
-18987,
-18945,
-18880,
-18792,
-18682,
-18549,
-18393,
-18216,
-18017,
-17797,
-17557,
-17296,
-17015,
-16716,
-16398,
-16062,
-15710,
-15341,
-14957,
-14558,
-14145,
-13720,
-13282,
-12834,
-12375,
-11908,
-11432,
-10950,
-10461,
-9967,
-9470,
-8970,
-8468,
-7965,
-7463,
-6962,
-6464,
-5969,
-5479,
-4995,
-4517,
-4048,
-3587,
-3135,
-2695,
-2266,
-1850,
-1447,
-1058,
-684,
-327,
14,
338,
644,
931,
1200,
1448,
1677,
1885,
2072,
2238,
2381,
2503,
2603,
2681,
2736,
2769,
2779,
2767,
2732,
2675,
2597,
2496,
2374,
2231,
2067,
1882,
1678,
1454,
1212,
951,
672,
377,
65,
-261,
-603,
-960,
-1329,
-1711,
-2104,
-2508,
-2921,
-3343,
-3774,
-4210,
-4653,
-5101,
-5553,
-6008,
-6464,
-6922,
-7380,
-7837,
-8292,
-8744,
-9192,
-9636,
-10074,
-10505,
-10929,
-11345,
-11752,
-12150,
-12536,
-12912,
-13275,
-13626,
-13963,
-14287,
-14596,
-14890,
-15169,
-15432,
-15679,
-15909,
-16122,
-16319,
-16498,
-16659,
-16803,
-16929,
-17038,
-17129,
-17202,
-17258,
-17296,
-17318,
-17322,
-17310,
-17281,
-17237,
-17177,
-17101,
-17012,
-16908,
-16790,
-16660,
-16518,
-16363,
-16198,
-16022,
-15837,
-15643,
-15441,
-15232,
-15016,
-14794,
-14568,
-14338,
-14104,
-13868,
-13631,
-13393,
-13156,
-12919,
-12685,
-12453,
-12224,
-12001,
-11782,
-11569,
-11363,
-11165,
-10974,
-10793,
-10620,
-10458,
-10307,
-10167,
-10039,
-9923,
-9820,
-9730,
-9654,
-9592,
-9544,
-9510,
-9491,
-9487,
-9498,
-9524,
-9565,
-9621,
-9692,
-9778,
-9879,
-9995,
-10125,
-10269,
-10427,
-10599,
-10783,
-10980,
-11189,
-11409,
-11641,
-11883,
-12135,
-12395,
-12664,
-12941,
-13224,
-13514,
-13809,
-14108,
-14411,
-14716,
-15023,
-15331,
-15638,
-15945,
-16250,
-16551,
-16849,
-17142,
-17429,
-17709,
-17981,
-18245,
-18499,
-18742,
-18974,
-19193,
-19399,
-19591,
-19768,
-19930,
-20075,
-20202,
-20312,
-20402,
-20474,
-20525,
-20557,
-20566,
-20555,
-20521,
-20465,
-20387,
-20285,
-20160,
-20011,
-19838,
-19642,
-19422,
-19177,
-18909,
-18617,
-18301,
-17962,
-17599,
-17213,
-16804,
-16373,
-15920,
-15445,
-14950,
-14434,
-13898,
-13343,
-12769,
-12177,
-11569,
-10944,
-10303,
-9649,
-8980,
-8299,
-7606,
-6902,
-6188,
-5465,
-4735,
-3998,
-3256,
-2508,
-1758,
-1005,
};
