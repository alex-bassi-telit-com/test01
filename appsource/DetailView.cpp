//---------------------------------------------------------------------------

#include <fmx.h>
#pragma hdrstop

#include "DetailView.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.fmx"
TDetailViewForm *DetailViewForm;
//---------------------------------------------------------------------------
__fastcall TDetailViewForm::TDetailViewForm(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TDetailViewForm::FormGesture(TObject *Sender, const TGestureEventInfo &EventInfo,
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

void __fastcall TDetailViewForm::FormMouseUp(TObject *Sender, TMouseButton Button, TShiftState Shift,
		  float X, float Y)
{
	ShowToolbar(Button == TMouseButton::mbRight);
}
//---------------------------------------------------------------------------
void TDetailViewForm::ShowToolbar(bool AShow)
{
  ToolbarPopup->Width = ClientWidth;
  ToolbarPopup->PlacementRectangle->Rect = TRect(0, ClientHeight-ToolbarPopup->Height, ClientWidth-1, ClientHeight-1);
  ToolbarPopupAnimation->StartValue = ToolbarPopup->Height;
  ToolbarPopupAnimation->StopValue = 0;

  ToolbarPopup->IsOpen = AShow;
}
//---------------------------------------------------------------------------
void __fastcall TDetailViewForm::HeaderButtonClick(TObject *Sender)
{
	Close();
}
//---------------------------------------------------------------------------
void __fastcall TDetailViewForm::FormKeyDown(TObject *Sender, WORD &Key, System::WideChar &KeyChar,
          TShiftState Shift)
{
  if (Key == vkEscape) {
	  Close();
  }
}
//---------------------------------------------------------------------------

void __fastcall TDetailViewForm::FormActivate(TObject *Sender)
{
	WindowState = TWindowState::wsMaximized;
}
//---------------------------------------------------------------------------
