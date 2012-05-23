int i = 0;                       // variable

void setup()
  {
    // initialize serial port
    Serial.begin(115200);        // open the serial port at 9600 bps:    
  }

void loop()
  {  
    // print labels 
    Serial.print("ASCII");       // prints a label
    Serial.print("\t");          // prints a tab
    
    Serial.print("DEC");
    Serial.print("\t");
    
    Serial.print("HEX"); 
    Serial.print("\t");
    
    Serial.print("BIN");
    Serial.println("\t"); 
    
    for(i=32; i< 128; i++)       // only part of the ASCII chart
      {     
        
        Serial.write(i);         // print as an ASCII Symbol
        Serial.print("\t");      // prints a tab
        
        Serial.print(i, DEC);    // print as an ASCII-encoded decimal
        Serial.print("\t");      // prints a tab
        
        Serial.print(i, HEX);    // print as an ASCII-encoded hexadecimal
        Serial.print("\t");      // prints a tab
        
        Serial.print(i, BIN);    // print as an ASCII-encoded binary
        Serial.println("");      // carriage return with "println"
        
        delay(20);               // delay 20 milliseconds
      }
    Serial.println("");          // prints another carriage return
    delay(10000);                // delay 10 seconds
  }
  
/*
Output:

ASCII	DEC	HEX	BIN	
 	32	20	100000
!	33	21	100001
"	34	22	100010
#	35	23	100011
$	36	24	100100
%	37	25	100101
&	38	26	100110
'	39	27	100111
(	40	28	101000
)	41	29	101001
*	42	2A	101010
+	43	2B	101011
,	44	2C	101100
-	45	2D	101101
.	46	2E	101110
/	47	2F	101111
0	48	30	110000
1	49	31	110001
2	50	32	110010
3	51	33	110011
4	52	34	110100
5	53	35	110101
6	54	36	110110
7	55	37	110111
8	56	38	111000
9	57	39	111001
:	58	3A	111010
;	59	3B	111011
<	60	3C	111100
=	61	3D	111101
>	62	3E	111110
?	63	3F	111111
@	64	40	1000000
A	65	41	1000001
B	66	42	1000010
C	67	43	1000011
D	68	44	1000100
E	69	45	1000101
F	70	46	1000110
G	71	47	1000111
H	72	48	1001000
I	73	49	1001001
J	74	4A	1001010
K	75	4B	1001011
L	76	4C	1001100
M	77	4D	1001101
N	78	4E	1001110
O	79	4F	1001111
P	80	50	1010000
Q	81	51	1010001
R	82	52	1010010
S	83	53	1010011
T	84	54	1010100
U	85	55	1010101
V	86	56	1010110
W	87	57	1010111
X	88	58	1011000
Y	89	59	1011001
Z	90	5A	1011010
[	91	5B	1011011
\	92	5C	1011100
]	93	5D	1011101
^	94	5E	1011110
_	95	5F	1011111
`	96	60	1100000
a	97	61	1100001
b	98	62	1100010
c	99	63	1100011
d	100	64	1100100
e	101	65	1100101
f	102	66	1100110
g	103	67	1100111
h	104	68	1101000
i	105	69	1101001
j	106	6A	1101010
k	107	6B	1101011
l	108	6C	1101100
m	109	6D	1101101
n	110	6E	1101110
o	111	6F	1101111
p	112	70	1110000
q	113	71	1110001
r	114	72	1110010
s	115	73	1110011
t	116	74	1110100
u	117	75	1110101
v	118	76	1110110
w	119	77	1110111
x	120	78	1111000
y	121	79	1111001
z	122	7A	1111010
{	123	7B	1111011
|	124	7C	1111100
}	125	7D	1111101
~	126	7E	1111110
	127	7F	1111111
*/
