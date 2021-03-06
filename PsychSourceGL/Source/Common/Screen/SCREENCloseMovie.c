/*

 Psychtoolbox3/Source/Common/SCREENCloseMovie.c		

 

 AUTHORS:

 mario.kleiner at tuebingen.mpg.de   mk

 

 PLATFORMS:	

 This file should build on any platform. 

 

 HISTORY:

 10/23/05  mk		Created. 

 

 DESCRIPTION:

 

 Close a previously opened movie file and release all associated ressources.

 

 On OS-X, all movie/multimedia handling functions are implemented via the Apple Quicktime API,

 version 7 or later. On a later Windows port we'll probably do the same, but for other OS'es,

 e.g., Linux, we would use a different multimedia engine.

 

 TO DO:

 

 

 

 

 */





#include "Screen.h"





static char useString[] = "Screen('CloseMovie', moviePtr);";

static char synopsisString[] = 

	"Close movie object specified by 'moviePtr' and release all associated ressources.";

static char seeAlsoString[] = "CloseMovie PlayMovie GetMovieImage GetMovieTimeIndex SetMovieTimeIndex";

	 



PsychError SCREENCloseMovie(void) 

{

    int                                     moviehandle = -1;

    

    // All sub functions should have these two lines

    PsychPushHelp(useString, synopsisString, seeAlsoString);

    if(PsychIsGiveHelp()) {PsychGiveHelp(); return(PsychError_none);};

    

    PsychErrorExit(PsychCapNumInputArgs(1));            // Max. 1 input args.

    PsychErrorExit(PsychRequireNumInputArgs(1));        // Min. 1 input args required.

    PsychErrorExit(PsychCapNumOutputArgs(0));           // No output args.

    

    // Get the window record from the window record argument and get info from the window record

    //PsychAllocInWindowRecordArg(kPsychUseDefaultArgPosition, TRUE, &windowRecord);

    // Only onscreen windows allowed:

    //if(!PsychIsOnscreenWindow(windowRecord)) {

      //  PsychErrorExitMsg(PsychError_user, "OpenMovie called on something else than an onscreen window.");

    //}

    

    // Get the movie handle:

    PsychCopyInIntegerArg(1, TRUE, &moviehandle);

    if (moviehandle==-1) {

        PsychErrorExitMsg(PsychError_user, "CloseMovie called without valid handle to a movie object.");

    }

    

    // Try to delete the movie object, releasing all associated ressources:

    PsychDeleteMovie(moviehandle);

    

    // Ready!    

    return(PsychError_none);

}










