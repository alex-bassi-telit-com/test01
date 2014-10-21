//---------------------------------------------------------------------------

#include <fmx.h>
#pragma hdrstop

#include "MainGridView.h"
#include "DetailView.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.fmx"
TGridViewForm *GridViewForm;
//---------------------------------------------------------------------------
__fastcall TGridViewForm::TGridViewForm(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TGridViewForm::ItemClick(TObject *Sender)
{
	TCommonCustomForm *Form = Application->GetDeviceForm(L"DetailView");
        if (Form)
                Form->Show();
}
//---------------------------------------------------------------------------

void __fastcall TGridViewForm::FormGesture(TObject *Sender, const TGestureEventInfo &EventInfo,
		  bool &Handled)
{
	float DX, DY;

	if (EventInfo.GestureID == igiPan) {
		if (EventInfo.Flags.Contains(TInteractiveGestureFlag::gfBegin)
		  && (Sender == ToolbarPopup || EventInfo.Location.Y > (ClientHeight - 70))) {
			FGestureOrigin = EventInfo.Location;
			FGestureInProgress = true;
		}
	}

	if (FGestureInProgress && EventInfo.Flags.Contains(TInteractiveGestureFlag::gfEnd)) {
		FGestureInProgress = false;
		DX = EventInfo.Location.X - FGestureOrigin.X;
		DY = EventInfo.Location.Y - FGestureOrigin.Y;
		if (fabs(DY) > fabs(DX)) {
			ShowToolbar(DY < 0);
		}
	}
}
//---------------------------------------------------------------------------

void __fastcall TGridViewForm::FormMouseUp(TObject *Sender, TMouseButton Button, TShiftState Shift,
		  float X, float Y)
{
	ShowToolbar(Button == TMouseButton::mbRight);
}
//---------------------------------------------------------------------------
void TGridViewForm::ShowToolbar(bool AShow)
{
  ToolbarPopup->Width = ClientWidth;
  ToolbarPopup->PlacementRectangle->Rect = TRect(0, ClientHeight-ToolbarPopup->Height, ClientWidth-1, ClientHeight-1);
  ToolbarPopupAnimation->StartValue = ToolbarPopup->Height;
  ToolbarPopupAnimation->StopValue = 0;

  ToolbarPopup->IsOpen = AShow;
}
//---------------------------------------------------------------------------

void __fastcall TGridViewForm::FormKeyDown(TObject *Sender, WORD &Key, System::WideChar &KeyChar,
          TShiftState Shift)
{
  if (Key == vkEscape) {
	  ShowToolbar(!ToolbarPopup->IsOpen);
  }
}
//---------------------------------------------------------------------------

void __fastcall TGridViewForm::ToolbarCloseButtonClick(TObject *Sender)
{
	Application->Terminate();
}
//---------------------------------------------------------------------------
