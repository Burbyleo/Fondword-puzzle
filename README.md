# Fondword-puzzle

Findword puzzle is defined by a 2D array of letters and a list of words. To solve the puzzle all words from the list must be located in the 2D array of letters and the letters corresponding to the word shall be "struck out".

When all words from the list are completed, the remaining letters (which were not struck out) read int left-to-right, top-to-bottom manner form the solution of the puzzle. The words may be located anywhere in the 2D array - they may be read left-to-right, right-to-left, top-down, down-top, or diagonally. One letter may participate in several words, the words may overlap, a word from the list may appear several times in the 2D array.

The input of the program is the findword puzzle. The input consists of the 2D array, an empty line, and a list of words to search for. The 2D array must be of a rectangular shape, only lowercase letters and period character may appear in the 2D array (the period stands for an unused cell). The list of words is delivered as one word per line. The word list ends with the end of the input.

The output is the solution of the puzzle. 


Sample use of the program:

1) Enter your wordfind puzzle:
dsjellivhsanxrr
riemjudhgdffcfz
elfkumrayldwory
iofcnoorteyclit
lperenfriitnuci
earaatticfspmhc
pnsmugrsegarbma
taoshoabknioiom
niniomhuainvano
odcbnexrlrtirdh
mnicorwgtppdepa
witslyxolsaevll
xhybuvoyaxunnvk
atnaltapsllcelo
ryedunuhyxhedfy

atlanta
saltlakecity
indianapolis
montpelier
juneau
bismarck
oklahomacity
saintpaul
denver
honolulu
richmond
harrisburg
columbia
nashville
springfield
providence
montgomery
hartford
jeffersoncity
Result:
dxrrmugfffzdwyctnxcwpwsxolxhbvoyxvpllryednuhyxhfy

2)Enter your wordfind puzzle:
............xcx............
.........qeztodlea.........
.......ecnedivorpuzy.......
.....bqfjwxqindnrsatrs.....
....ucaamadisonoctoieax....
...ozkttqdxwltstaivcilex...
...ujknnakigzfasxninltxc...
..rabxaa...kohce...oelnyd..
..rithls...momrl...spayvh..
.awecktlukrnloardaartkrhxu.
.lqezhacyooyznmapqaenemrqg.
.besldmyelpnltehshefocgnhd.
daasizoouuhjigncoavfmiokwsn
jncanfblnnoueotzqkyehtwduip
rywhcjuowdentmoniewjnyeypcs
.adao.wljwneoenazpgea.ofoq.
.icll..ntciaxrlraoru..mlev.
.tflnk..xtxueyakgth..vummp.
..tayie.............xmmee..
..htgjbj...........mbflvq..
...littlerockihhcftidaja...
...oklahomacityzoyapsshm...
....kjehgufspringfieldr....
.....fjwyjjmnwdenverzl.....
.......qnarzlhejwwtc.......
.........enneyehcn.........
............jjy............

honolulu
oklahomacity
charleston
madison
montgomery
saltlakecity
springfield
juneau
tallahassee
providence
phoenix
santafe
trenton
albany
lincoln
jeffersoncity
atlanta
austin
littlerock
sacramento
topeka
denver
cheyenne
montpelier
salem
richmond
columbia
Result:
xcxqeztodlezbqjwxqindrauccoxozkqdxwltavexujkakigzfxixcabxkon
ydrthmyvhwklukrldaarhxuqzcyoyzpqamrqgedyenlsheghddazouiovkws
njcfbnezqyhwduiprwjowtniweypsadwljwonazgaofqicntcxlraumevtfk
xteakghvmptyiexmehgjbjmfvqihhcftdjazoypshmkjehgufrfjwyjjmnwz
lqnarzlhejwwtcnjjy
