//---------------------------------------------------------------------------

#ifndef DetailViewH
#define DetailViewH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <FMX.Controls.hpp>
#include <FMX.Forms.hpp>
#include <FMX.Types.hpp>
#include <FMX.Ani.hpp>
#include <FMX.Layouts.hpp>
#include <FMX.Gestures.hpp>
#include <FMX.StdCtrls.hpp>
//---------------------------------------------------------------------------
class TDetailViewForm : public TForm
{
__published:	// IDE-managed Components
	TLayout *ToolbarHolder;
	TPopup *ToolbarPopup;
	TToolBar *ToolBar1;
	TFloatAnimation *ToolbarPopupAnimation;
	TLayout *MainLayout;
	TLayout *HeaderLayout;
	TLabel *TitleLabel1;
	TLayout *Layout2;
	TButton *HeaderButton;
	THorzScrollBox *HorzScrollBox1;
	TLayout *Column1;
	TLayout *ArticleHeaderLayout;
	TImageControl *Illustration1;
	TLayout *Layout4;
	TLabel *ItemTitle;
	TLabel *ItemSubTitle;
	TLabel *Label1;
	TLayout *Column2;
	TLabel *Label2;
	TLabel *Label3;
	TLayout *Column3;
	TLabel *Label4;
	void __fastcall FormGesture(TObject *Sender, const TGestureEventInfo &EventInfo,
          bool &Handled);
	void __fastcall FormMouseUp(TObject *Sender, TMouseButton Button, TShiftState Shift,
          float X, float Y);
	void __fastcall HeaderButtonClick(TObject *Sender);
	void __fastcall FormKeyDown(TObject *Sender, WORD &Key, System::WideChar &KeyChar,
          TShiftState Shift);
	void __fastcall FormActivate(TObject *Sender);
private:	// User declarations
	TPointF FGestureOrigin;
	bool FGestureInProgress;
	void ShowToolbar(bool AShow);
public:		// User declarations
	__fastcall TDetailViewForm(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TDetailViewForm *DetailViewForm;
//---------------------------------------------------------------------------
#endif
