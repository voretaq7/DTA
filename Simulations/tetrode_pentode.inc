**********************************************************************
* voretaq7's collected tetrode & pentode tube models
*
* Updated 2015-12-07
*
* Models Contained:
*
* --- 6L6	: 6L6
* --- 6BM8	: 6BM8,   ECL82
* --- 6BQ5	: 6BQ5,   EL84
* --- 6CA7	: 6CA7,   EL34
* --- 6KG6      : 6KG6,   EL509
* --- 6V6GTA	: 6V6GTA, 6AQ5A,   7408,     6669
* --- EF86      : EF86
* --- KT66	: KT66
* --- KT88	: KT88
**********************************************************************

*-----------------------------------------------------------------------
* Filename:		dm6L6.inc  V2 12/10/97
* Simulator:		PSpice
* Device type:		Power beam tetrode
* Device model:		6L6 (and variants)
*
* Author:		Duncan Munro
* Date:			4/6/97
* Copyright:		(C)1997-2000 Duncan Amplification
*
* V2 [12/10/97]: Screen current limited to prevent screen current
*		 draw at Vs = 0.
* 
* The following parameters are not modelled:
*
*   (1) Heater
*   (2) Grid current is an approximation
*
* Please note that this model is provided "as is" and
* no warranty is provided in respect of its suitability
* for any application.
*
* This model is provided for educational and non-profit use.
*
* Email queries to postmaster@duncanamps.com
*
* Pins   A  Anode
*        S  Screen
*        G  Grid
*        K  Cathode
*
*-----------------------------------------------------------------------

.SUBCKT 6L6 A S G K
*
* Calculate contribution to cathode current
*
Eat	at	0	VALUE={0.636*ATAN(V(A,K)/5)}
Eme	me	0	VALUE={PWR(LIMIT{V(A,K),0,2000},1.5)/1750}
Emu	mu	0	VALUE={PWRS(V(G,K),1-(LIMIT{-V(G,K),30,9999}-30)/2000)}
Egs	gs	0	VALUE={LIMIT{V(A,K)/2.5+V(S,K)*15.15+V(mu)*134,0,1E6}}
Egs2	gs2	0	VALUE={PWRS(V(gs),1.5)*0.8E-6}
Ecath  	cc    	0 	VALUE={LIMIT{V(gs2)*V(at),0,V(me)}}
*
* Calculate anode current
*
Ga     	A     	K     	VALUE={V(cc)}
*
* Calculate screen current
*
Escrn	sc	0	VALUE={0.76*V(gs2)*(1.1-V(at))}
Gs     	S     	K	VALUE={V(sc)*LIMIT{V(S,K),0,10}/10}
*
* Grid current
*
Gg	G	K	VALUE={PWR(LIMIT{V(G,K)+1,0,1E6},1.5)*(1.25-V(at))*650E-6}
*
* Capacitances
*
Cg1	G	K	5.0p
Cgs	G	S	5.0p
Cak	A	K	6.5p
Cg1a	G	A	0.6p

.ENDS 


*-----------------------------------------------------------------------
* Filename:		6bm8p.inc  03/03/99  V1
* Simulator:		PSpice
* Device type:		Power pentode
* Device model:		6BM8/ECL82
*
* Author:		Duncan Munro
* Date:			3/3/99
* Copyright:		(C)1999-2000 Duncan Amplification
*
*
* The following parameters are not modelled:
*
*   (1) Heater
*   (2) Grid current
*
* Please note that this model is provided "as is" and
* no warranty is provided in respect of its suitability
* for any application.
*
* This model is provided for educational and non-profit use.
*
* Email queries to postmaster@duncanamps.com
*
* Pins   A  Anode
*        S  Screen
*        G  Grid
*        K  Cathode
*
*-----------------------------------------------------------------------

.SUBCKT 6BM8P A S G K
*
* Calculate contribution to cathode current
*
Eat	at	0	VALUE={0.636*ATAN(V(A,K)/15)}
Egs	gs	0	VALUE={LIMIT{V(S,K)/7+V(G,K)*1.3+V(A,K)/700,0,1E6}}
Egs2	gs2	0	VALUE={PWRS(V(gs),1.24)}
Ecath  	cc    	0 	VALUE={V(gs2)*V(at)}
*
* Calculate anode current
*
Ga     	A     	K     	VALUE={3.45E-3*V(cc)}
*
* Calculate screen current
*
Escrn	sc	0	VALUE={V(gs2)*(1.1-V(at))}
Gs     	S     	K	VALUE={3.7E-3*V(sc)*LIMIT{V(S,K),0,10}/10}
*
* Capacitances
*
Cg1	G	K	9.6p
Cak	A	K	9.3p
Cg1a	G	A	0.35p

.ENDS 


*-----------------------------------------------------------------------
* Filename:		6bq5.inc  23/01/2004  V4
* Simulator:		PSpice
* Device type:		Power pentode
* Device model:		6BQ5/EL84
*
* Author:		Duncan Munro
* Date:			12/5/97
* Copyright:		(C)1997-2004 Duncan Amplification
*
*
* V3 [12/10/97]: Screen current limited to prevent screen current
*		 draw at Vs = 0.
*
* V4 [23/01/04]: LIMIT{x,y,z} statements changed to LIMIT(x,y,z)
* 
* The following parameters are not modelled:
*
*   (1) Heater
*   (2) Grid current is an approximation
*
* Please note that this model is provided "as is" and
* no warranty is provided in respect of its suitability
* for any application.
*
* This model is provided for educational and non-profit use.
*
* Queries via the forum at http://www.duncanamps.com/
*
* Pins   A  Anode
*        S  Screen
*        G  Grid
*        K  Cathode
*
*-----------------------------------------------------------------------

.SUBCKT 6BQ5 A S G K
*
* Calculate contribution to cathode current
*
Eat	at	0	VALUE={0.636*ATAN(V(A,K)/15)}
Egs	gs	0	VALUE={LIMIT(V(S,K)/19+V(G,K)+V(A,K)/1400,0,1E6)}
Egs2	gs2	0	VALUE={PWRS(V(gs),1.5)}
Ecath  	cc    	0 	VALUE={V(gs2)*V(at)}
*
* Calculate anode current
*
Ga     	A     	K     	VALUE={3.2E-3*V(cc)}
*
* Calculate screen current
*
Escrn	sc	0	VALUE={V(gs2)*(1.1-V(at))}
Gs     	S     	K	VALUE={2.0E-3*V(sc)*LIMIT(V(S,K),0,10)/10}
*
* Grid current (approximation - does not model low va/vs)
*
Gg	G	K	VALUE={PWR(LIMIT(V(G,K)+1,0,1E6),1.5)*50E-6}
*
* Capacitances
*
Cg1	G	K	10.8p
Cak	A	K	6.5p
Cg1a	G	A	0.5p

.ENDS 


*-----------------------------------------------------------------------
* Filename:		6ca7.inc  V3 23/01/2004
* Simulator:		PSpice
* Device type:		Power pentode
* Device model:		6CA7/EL34
*
* Author:		Duncan Munro
* Date:			2/5/97
* Copyright:		(C)1997-2004 Duncan Amplification
*
*
* V2 [12/10/97]: Screen current limited to prevent screen current
*		 draw at Vs = 0.
*
* V4 [23/01/04]: LIMIT{x,y,z} statements changed to LIMIT(x,y,z)
* 
* The following parameters are not modelled:
*
*   (1) Heater
*   (2) Grid current is an approximation
*
* Please note that this model is provided "as is" and
* no warranty is provided in respect of its suitability
* for any application.
*
* This model is provided for educational and non-profit use.
*
* Queries via the forum at http://www.duncanamps.com/
*
* Pins   A  Anode
*        S  Screen
*        G  Grid
*        K  Cathode
*
*-----------------------------------------------------------------------

.SUBCKT 6CA7 A S G K
*
* Calculate contribution to cathode current
*
Eat	at	0	VALUE={0.636*ATAN(V(A,K)/23)}
Egs	gs	0	VALUE={LIMIT(V(S,K)/9.3+V(G,K)*0.95,0,1E6)}
Egs2	gs2	0	VALUE={PWRS(V(gs),1.5)}
Ecath  	cc    	0 	VALUE={V(gs2)*V(at)}
*
* Calculate anode current
*
Ga     	A     	K     	VALUE={1.86E-3*V(cc)}
*
* Calculate screen current
*
Escrn	sc	0	VALUE={V(gs2)*(1.1-V(at))}
Gs     	S     	K	VALUE={1.518E-3*V(sc)*LIMIT(V(S,K),0,10)/10}
*
* Grid current (approximation - does not model low va/vs)
*
Gg	G	K	VALUE={PWR(LIMIT(V(G,K)+1,0,1E6),1.5)*50E-6}
*
* Capacitances
*
Cg1	G	K	15.4p
Cak	A	K	8.4p
Cg1a	G	A	1.1p

.ENDS 



*-----------------------------------------------------------------------
* Filename:		6kg6.inc  V2 12/10/97
* Simulator:		PSpice
* Device type:		Power pentode
* Device model:		6KG6/EL509
*			(also 40KG6/PL509 as no heater model)
*
* Author:		Duncan Munro
* Date:			21/7/97
* Copyright:		(C)1997-2000 Duncan Amplification
*
*
* V2 [12/10/97]: Screen current limited to prevent screen current
*		 draw at Vs = 0.
* 
* The following parameters are not modelled:
*
*   (1) Heater
*   (2) Grid current is an approximation in the absence
*       of suitable data
*
* Also see comments below, as the Svetlana EL509 is of different
* construction and has different capacitances.
*
* Please note that this model is provided "as is" and
* no warranty is provided in respect of its suitability
* for any application.
*
* This model is provided for educational and non-profit use.
*
* Email queries to postmaster@duncanamps.com
*
* Pins   A  Anode
*        S  Screen
*        G  Grid
*        K  Cathode
*
*-----------------------------------------------------------------------

.SUBCKT 6KG6 A S G K
*
* Calculate contribution to cathode current
*
Eat	at	0	VALUE={0.636*ATAN(V(A,K)/20)}
Eme	me	0	VALUE={PWR(LIMIT{V(A,K),0,10000},1.5)/17}
Emu	mu	0	VALUE={PWRS(V(G,K),1-(LIMIT{-V(G,K),5,9999}-5)/1150)}
Egs	gs	0	VALUE={LIMIT{V(S,K)/19+V(mu)/4.3+V(A,K)/800,0,1E6}}
Egs2	gs2	0	VALUE={PWRS(V(gs),1.5)}
Ecath  	cc    	0 	VALUE={LIMIT{V(gs2)*V(at),0,V(me)}}
Elim	el	0	VALUE={LIMIT{V(gs2)*V(at)-V(cc),0,99999}}
*
* Calculate anode current
*
Ga     	A     	K     	VALUE={6E-2*V(cc)}
*
* Calculate screen current
*
Escrn	sc	0	VALUE={V(gs2)*(1.1-V(at))+1.2*V(el)}
Gs     	S     	K	VALUE={1.2E-2*V(sc)*LIMIT{V(S,K),0,10}/10}
*
* Grid current (approximation - does not model low va/vs)
*
Gg	G	K	VALUE={PWR(LIMIT{V(G,K)+1,0,1E6},1.5)*50E-6}
*
* Capacitances
* NOTE: Change Cg1 from 37p to 25p for Svetlana EL509
*
Cg1	G	K	37p
Cak	A	K	18.5p
Cg1a	G	A	2.5p

.ENDS

 
* -------------------------------------------------------------------
* 6V6GTA Beam Power Tube PSpice Model            8/96, Rev. 1.0  (fp)
*
* -------------------------------------------------------------------
*  This model is provided "as is", with no warranty of any kind,
*  either expressed or implied, about the suitability or fitness
*  of this model for any particular purpose.  Use of this model
*  shall be entirely at the user's own risk.
*
*  For a discussion about vacuum tube modeling please refer to:
*  W. Marshall Leach, jr: "SPICE Models for Vacuum-Tube Amplifiers";
*  J. Audio Eng. Soc., Vol 43, No 3, March 1995.
* -------------------------------------------------------------------
*
* This model is valid for the following tubes (within max. ratings):
*                   6V6GTA,   6AQ5A/EL90,
*                   7408,     6669.
* --------------+----------------------------
* Plate Dissip. :    14W          12W
* Screen Input  :   2.2W         2.0W
* Plate Voltage :   350V         275V
* Screen Voltage:   315V         275V
*
* at the following conditions:
*  Plate voltage  : 0..500V
*  Screen voltage : 0..450V
*  Grid voltage   : 0..-50V
*  Cathode current: 0..200mA
*
*
* Connections: Plate
*              | Screen Grid
*              | | Control Grid
*              | | | Cathode
*              | | | |
.SUBCKT 6V6GTA P S G K
Esp 2  0  VALUE={V(P,K)+13.49*V(S,K)+130.4*V(G,K)}
E1  3  2  VALUE={5.521E-7*(PWR(V(2),1.5)+PWRS(V(2),1.5))/2}
E2  3  4  VALUE={5.521E-7*PWR(13.49*V(S,K),1.5)*V(P,K)/25}
E3  5  4  VALUE={(1-V(4,2)/ABS(V(4,2)+0.001))/2}
R1  5  0  1.0K
Gk  S  K  VALUE={V(3,2)}
Gp  P  S  VALUE={0.92*(V(3,4)*(1-V(5,4))+V(3,2)*V(5,4))}
Cgk G  K  4.5P
Cgs G  S  4.5P
Cgp G  P  0.7P
Cpk P  K  7.5P
.ENDS 6V6GTA



*-----------------------------------------------------------------------
* Filename:		EF86.inc  17/5/97 (Version 3)
* Simulator:		PSpice
* Device type:		Pentode
* Device model:		EF86
*
* Author:		Duncan Munro
* Date:			16/5/97
* Copyright:		(C)1997-2000 Duncan Amplification
* 
* The following parameters are not modelled:
*
*   (1) Heater
*   (2) Grid current
*
* Please note that this model is provided "as is" and
* no warranty is provided in respect of its suitability
* for any application.
*
* This model is provided for educational and non-profit use.
*
* Email queries to postmaster@duncanamps.com
*
* Pins   A  Anode
*        S  Screen
*        G  Grid
*        K  Cathode
*
*-----------------------------------------------------------------------

.SUBCKT EF86 A S G K

*
* Calculate reduction in mu when Vg < -3V
*
Emu	mu	0	VALUE={LIMIT{V(G,K),-3,999}+LIMIT{V(G,K)+3,-999,0}*0.714}
*
* Calculate contribution to cathode current
*
Eat	at	0	VALUE={0.636*ATAN(V(A,K)/15)}
Egs	gs	0	VALUE={LIMIT{V(S,K)/27.5+V(mu)*1.32+1,0,1E6}}
Egs2	gs2	0	VALUE={PWRS(V(gs),1.5)}
Ecath  	cc    	0 	VALUE={V(gs2)*V(at)}
*
* Calculate anode current
*
Ga     	A     	K     	VALUE={5.83E-4*V(cc)}
*
* Calculate screen current
*
Escrn	sc	0	VALUE={V(gs2)*(1.1-V(at))}
Gs     	S     	K	VALUE={0.5E-3*V(sc)}
*
* Capacitances
*
Cg1	G	K	3.8p
Cak	A	K	5.3p
Cg1a	G	A	0.05p

.ENDS 



* -------------------------------------------------------------------
* KT66 Beam Power Tube PSpice Model       2015-12-07 - Source Unknown
*
* -------------------------------------------------------------------
.SUBCKT KT66  1 2 3 4 ; A G2 G1 C (Beam Tetrode)
* M-O Valve Co AKA Genalex
+ PARAMS: MU=11.68 EX=1.197 KG1=510.9 KG2=4500 KP=34 KVB=22.3
+         VCT=0.00 RGI=1000 CCG=16.0p CPG1=2.3p CCP=10.0p
RE1  7 0  1MEG    ; DUMMY SO NODE 7 HAS 2 CONNECTIONS
E1   7 0  VALUE=	; E1 BREAKS UP LONG EQUATION FOR G1.
+{V(2,4)/KP*LOG(1+EXP((1/MU+V(3,4)/V(2,4))*KP))}
G1   1 4  VALUE={(PWR(V(7),EX)+PWRS(V(7),EX))/KG1*ATAN(V(1,4)/KVB)}
G2   2 4  VALUE={(EXP(EX*(LOG((V(2,4)/MU)+V(3,4)))))/KG2}
RCP  1 4  1G      ; FOR CONVERGENCE	A  - C
C1   3 4  {CCG}   ; CATHODE-GRID 1	C  - G1
C2   1 3  {CPG1}  ; GRID 1-PLATE	G1 - A
C3   1 4  {CCP}   ; CATHODE-PLATE	A  - C
R1   3 5  {RGI}   ; FOR GRID CURRENT	G1 - 5
D3   5 4  DX      ; FOR GRID CURRENT	5  - C
.MODEL DX D(IS=1N RS=1 CJO=10PF TT=1N)
.ENDS    KT66



* -------------------------------------------------------------------
* KT88 Beam Power Tube PSpice Model              8/96, Rev. 1.0  (fp)
*
* -------------------------------------------------------------------
*  This model is provided "as is", with no warranty of any kind,
*  either expressed or implied, about the suitability or fitness
*  of this model for any particular purpose.  Use of this model
*  shall be entirely at the user's own risk.
*
*  For a discussion about vacuum tube modeling please refer to:
*  W. Marshall Leach, jr: "SPICE Models for Vacuum-Tube Amplifiers";
*  J. Audio Eng. Soc., Vol 43, No 3, March 1995.
* -------------------------------------------------------------------
*
* This model is valid for the following tubes (within max. ratings):
*                   KT88       6550.
* --------------+-----------------------
* Plate Dissip. :    35W        35W
* Screen Input  :     6W         6W
* Plate Voltage :   800V       600V
* Screen Voltage:   600V       400V
*
* at the following conditions:
*  Plate voltage  : 0..800V
*  Screen voltage : 0..600V
*  Grid voltage   : 0..-60V
*  Cathode current: 0..500mA
*
*
* Connections: Plate
*              | Screen Grid
*              | | Control Grid
*              | | | Cathode
*              | | | |
.SUBCKT   KT88 P S G K
Esp 2  0  VALUE={V(P,K)+24.49*V(S,K)+189.9*V(G,K)}
E1  3  2  VALUE={8.301E-7*(PWR(V(2),1.5)+PWRS(V(2),1.5))/2}
E2  3  4  VALUE={8.301 E-7*PWR(24.49*V(S,K),1.5)*V(P,K)/40}
E3  5  4  VALUE={(1-V(4,2)/ABS(V(4,2)+0.001))/2}
R1  5  0  1.0K
Gk  S  K  VALUE={V(3,2)}
Gp  P  S  VALUE={0.95*(V(3,4)*(1-V(5,4))+V(3,2)*V(5,4))}
Cgk G  K  8.0P
Cgs G  S  8.0P
Cgp G  P  1.2P
Cpk P  K  12P
.ENDS KT88
