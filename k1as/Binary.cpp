//**************************************************************************************************************
// CLASS: cBinary
//
// DESCRIPTION
// See comments in Binary.hpp.
//
// AUTHOR INFORMATION
// Kevin R. Burger
//
// Mailing Address:
// Computer Science & Engineering
// School of Computing, Informatics, and Decision Systems Engineering
// Arizona State University
// Tempe, AZ 85287-8809
//
// Email: burgerk@asu
// Web:	  http://kevin.floorsoup.com
//**************************************************************************************************************
#include "Binary.hpp"

//--------------------------------------------------------------------------------------------------------------
// Ctor.
//
// PSEUDOCODE
// In the member init list, initialize mBinOut with pBinFname. This will open the binary file for writing.
//--------------------------------------------------------------------------------------------------------------
???

//--------------------------------------------------------------------------------------------------------------
// Dtor.
//
// PSEUDOCODE
// Close the binary file.
//--------------------------------------------------------------------------------------------------------------
???

//--------------------------------------------------------------------------------------------------------------
// FUNCTION: Binary::Write
//
// DESCRIPTION
// Writes the binary to the file name passed to the ctor. The contents of the data segment pDataSeg is written
// first followed by the contents of the text segment pTextSeg.
//
// PSEUDOCODE
// Note: on input, mBinOut is ready to begin writing data to the file.
// Send the signature bytes "K1BIN" to mBinOut (hint: use cManipSize(5) to specify the number of bytes to write).
// initPC <- address of the text segment.
// Send initPC to mBinOut.
// Send the reserved 0 bytes to mBinOut.
// Send 0 for the type of the segment (data segment) to mBinOut.
// size <- size of the data segment.
// Send size to mBinOut.
// address <- address of the data segment.
// Send address to mBinOut.
// contents <- contents of the data segment.
// Send contents to mBinOut (hint: use cManipSize(size - 9) to specify the number of bytes to write.
// free the contents array.
// Send 1 for the type of the segment (text segment) to mBinOut.
// size <- size of the text segment.
// Send size to mBinOut.
// address <- address of the text segment.
// Send address to mBinOut.
// contents <- contents of the text segment.
// Send contents to mBinOut (hint: use cManipSize(size - 9) to specify the number of bytes to write.
// free the contents array.
//--------------------------------------------------------------------------------------------------------------
???
