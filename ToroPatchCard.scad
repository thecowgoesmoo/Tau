//Template for patch cards for the Behringer Toro synth
//which is a clone of the Moog Taurus I.
//
//Released under the MIT license.
//Richard Moore
//https://github.com/thecowgoesmoo/Tau

//Edit this section for each patch: 
t = " Space Dolphin";
//Settings are arranged in the same order as the interface
//left to right starting with the Glide fader. 
sets = [3,4,3,5,1,6,4,1,3,6,1,2]; //Tick marks (1 to 6)

//The remainder of the script is not patch-specific and 
//typically should not be edited. 
slotXs = [10,28,42,56.5,71,85.5,100,114.5,129,143.5,158,172.5];

//setsShift = (sets-1)*30/5; 				//mm


module pos(){
    //
    square([190,60],center=false);
    color("blue") translate([0,45,0]) text(t, size=8, valign="bottom");
}

module neg(){
    for (i = [0:11]) {
        translate([slotXs[i],(sets[i]-1)*30/5-31,0]) square([6,40],center=false);
        }
}

difference(){
    pos();
    neg();
}
//neg();