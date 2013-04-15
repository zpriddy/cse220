//**************************************************************************************************************
// CLASS: cArg
//
// DESCRIPTION
// Handles command line options and arguments.
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
#ifndef ARG_HPP
#define ARG_HPP

#include <string>
using std::string;

//==============================================================================================================
// CLASS: cArg
//==============================================================================================================
class cArg {

public:
	//==========================================================================================================
	// PUBLIC CONSTANT MEMBERS
	//==========================================================================================================

	// This is the exception number that is thrown if the source file name is missing on the command line.
	static int const constMissingSrcFname = 1;

	//==========================================================================================================
	// PUBLIC FUNCTION MEMBERS
	//==========================================================================================================

	//----------------------------------------------------------------------------------------------------------
	// Ctor.
	//----------------------------------------------------------------------------------------------------------
	cArg(unsigned pArgc, char **pArgv);

	//----------------------------------------------------------------------------------------------------------
	// Dtor.
	//----------------------------------------------------------------------------------------------------------
	~cArg()
	{
	}

	//----------------------------------------------------------------------------------------------------------
	// BinFname()
	//
	// DESCRIPTION
	// Accessor function for mBinFname.
	//----------------------------------------------------------------------------------------------------------
	string BinFname() const
	{
		return mBinFname;
	}

	//----------------------------------------------------------------------------------------------------------
	// SrcFname()
	//
	// DESCRIPTION
	// Accessor function for mSrcFname.
	//----------------------------------------------------------------------------------------------------------
	string SrcFname() const
	{
		return mSrcFname;
	}

protected:
	//==========================================================================================================
	// PROTECTED FUNCTION MEMBERS
	//==========================================================================================================

	//----------------------------------------------------------------------------------------------------------
	// BinFname()
	//
	// DESCRIPTION
	// Mutator function for mBinFname.
	//----------------------------------------------------------------------------------------------------------
	void BinFname(string const& pBinFname)
	{
		mBinFname = pBinFname;
	}
	//----------------------------------------------------------------------------------------------------------
	// SrcFname()
	//
	// DESCRIPTION
	// Mutator function for mSrcFname.
	//----------------------------------------------------------------------------------------------------------
	void SrcFname(string const& pSrcFname)
	{
		mSrcFname = pSrcFname;
	}

private:
	//==========================================================================================================
	// PRIVATE FUNCTION MEMBERS
	//==========================================================================================================

	//----------------------------------------------------------------------------------------------------------
	// Copy ctor.
	//----------------------------------------------------------------------------------------------------------
	cArg(cArg const& parg);

	//----------------------------------------------------------------------------------------------------------
	// operator=()
	//----------------------------------------------------------------------------------------------------------
	cArg& operator=(cArg const& pArg);

	//==========================================================================================================
	// PRIVATE DATA MEMBERS
	//==========================================================================================================

	unsigned   mArgc;
	char	 **mArgv;
	string	   mBinFname;
	string	   mSrcFname;
};

#endif