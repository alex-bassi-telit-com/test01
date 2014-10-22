//---------------------------------------------------------------------------

#include <fmx.h>
#pragma hdrstop
#include <tchar.h>
//---------------------------------------------------------------------------
USEFORM("MainGridView.cpp", GridViewForm);
USEFORM("DetailView.cpp", DetailViewForm);
//---------------------------------------------------------------------------
extern "C" int FMXmain()
{
	try
	{
		Application->Initialize();
		Application->CreateForm(__classid(TGridViewForm), &GridViewForm);
		Application->CreateForm(__classid(TDetailViewForm), &DetailViewForm);
		Application->RegisterFormFamily(L"Main", OPENARRAY(TComponentClass,
			(__classid(TGridViewForm))));
		Application->RegisterFormFamily(L"DetailView", OPENARRAY(TComponentClass,
			(__classid(TDetailViewForm))));
		Application->Run();
	}
	catch (Exception &exception)
	{
		Application->ShowException(&exception);
	}
	catch (...)
	{
		try
		{
			throw Exception("");
		}
		catch (Exception &exception)
		{
			Application->ShowException(&exception);
		}
	}
	return 0;
}
//---------------------------------------------------------------------------
