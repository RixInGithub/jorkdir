i made this cuz uhh there isnt a convenient and cross compatible way to read a directory

meet jorkdir, the ultimate library, whichs only purpose is to "jork" a directory. wow.

to call jorkdir, first include the library. this is done by git cloning this whole garbage into ur own clean code and bla bla bla fucking bla.

then, just simply |#include "jorkdir/jorkdir.h"|.

jorkdir's sig is simply this: |char**jorkdir(char*dir,int*sz);|

this means jorkdir returns an array of strings, accepts a |dir| as a string and a |sz| as a pointer to an integer while will point to the length of the output.

simple as that, open issues if this bugs the fuck out in your use case, and def dont feed user data, i am assuming YOU are the one who sanitizes my dirs you foul piece of shit.

the outputs items are file/folder names relative to |dir|. includes |..|, but NOT |.| for obvious reasons. (prob not so obvious now that i think abt it lmao)

i will come back if i want this as a rust lib

ofhvbieufhvcbweufbviugewbfviuebi