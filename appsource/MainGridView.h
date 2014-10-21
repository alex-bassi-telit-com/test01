//---------------------------------------------------------------------------

#ifndef MainGridViewH
#define MainGridViewH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <FMX.Controls.hpp>
#include <FMX.Forms.hpp>
#include <FMX.Types.hpp>
#include <FMX.Ani.hpp>
#include <FMX.Layouts.hpp>
#include <FMX.ListBox.hpp>
#include <FMX.Gestures.hpp>
#include <FMX.StdCtrls.hpp>
//---------------------------------------------------------------------------
class TGridViewForm : public TForm
{
__published:	// IDE-managed Components
	TLayout *ToolbarHolder;
	TPopup *ToolbarPopup;
	TToolBar *ToolBar1;
	TFloatAnimation *ToolbarPopupAnimation;
	TLayout *MainLayout;
	TLayout *HeaderLayout;
	TLabel *TitleLabel1;
	THorzScrollBox *HorzScrollBox1;
	TLayout *GroupLayout1;
	TListBox *ListBox1;
	TMetropolisUIListBoxItem *MetroListBoxItem6;
	TMetropolisUIListBoxItem *MetroListBoxItem1;
	TMetropolisUIListBoxItem *MetroListBoxItem2;
	TLabel *GroupTitle1;
	TLayout *GroupLayout2;
	TListBox *ListBox2;
	TMetropolisUIListBoxItem *MetroListBoxItem3;
	TMetropolisUIListBoxItem *MetroListBoxItem4;
	TLabel *GroupTitle2;
	TLayout *GroupLayout3;
	TListBox *ListBox3;
	TMetropolisUIListBoxItem *MetroListBoxItem7;
	TMetropolisUIListBoxItem *MetroListBoxItem8;
	TMetropolisUIListBoxItem *MetroListBoxItem9;
	TLabel *GroupTitle3;
	TStyleBook *StyleBook2;
	void __fastcall ItemClick(TObject *Sender);
	void __fastcall FormGesture(TObject *Sender, const TGestureEventInfo &EventInfo,
		  bool &Handled);
	void __fastcall FormMouseUp(TObject *Sender, TMouseButton Button, TShiftState Shift,
		  float X, float Y);
	void __fastcall FormKeyDown(TObject *Sender, WORD &Key, System::WideChar &KeyChar,
          TShiftState Shift);
	void __fastcall ToolbarCloseButtonClick(TObject *Sender);
private:	// User declarations
	TPointF FGestureOrigin;
	bool FGestureInProgress;
	void ShowToolbar(bool AShow);
public:		// User declarations
	__fastcall TGridViewForm(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TGridViewForm *GridViewForm;
//---------------------------------------------------------------------------
#endif
