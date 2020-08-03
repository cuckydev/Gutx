

signed int __stdcall DialogDebugStart(HWND hDlg, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
  int v4; 
  char v6; 
  UINT stage; 
  UINT scroll; 
  UINT speed; 
  UINT power; 
  UINT life; 
  FILE *file; 
  char v13; 
  UINT uValue; 
  UINT v15; 
  UINT v16; 
  UINT v17; 
  UINT v18; 
  FILE *v19; 

  if ( uMsg == WM_INITDIALOG )
  {
    DebugOptsPtr = lParam;
    v19 = 0;
    sprintf(&v13, "%s\\%s", temp_guxtPath, debugstart_Bin);
    v19 = fopen(&v13, "rb");
    if ( v19 )
    {
      ReadFromFile(&uValue, 0x14u, 1u, v19);
      fclose(v19);
    }
    else
    {
      memset(&uValue, 0, 0x14u);
    }
    SetDlgItemInt(hDlg, 1005, uValue, 1);
    SetDlgItemInt(hDlg, 1002, v15, 1);
    SetDlgItemInt(hDlg, 1003, v16, 1);
    SetDlgItemInt(hDlg, 1004, v17, 1);
    SetDlgItemInt(hDlg, 1006, v18, 1);
    SetDlgItemTextA(
      hDlg,
      1007,
      "1:Twin\r\n"
      "2:Machine\r\n"
      "3:Triangle\r\n"
      "4:Back\r\n"
      "5:Wide\r\n"
      "6:3Line\r\n"
      "7:Star\r\n"
      "8:Harpoon\r\n"
      "9:Anchor\r\n"
      "10:Rocket\r\n"
      "11:WMachine");
  }
  else
  {
    if ( uMsg != 273 )
      return 0;
    if ( (unsigned __int16)wParam == 1 )
    {
      file = 0;
      stage = GetDlgItemInt(hDlg, 1005, 0, 1);
      scroll = GetDlgItemInt(hDlg, 1002, 0, 1);
      speed = GetDlgItemInt(hDlg, 1003, 0, 1);
      power = GetDlgItemInt(hDlg, 1004, 0, 1);
      life = GetDlgItemInt(hDlg, 1006, 0, 1);
      sprintf(&v6, "%s\\%s", temp_guxtPath, debugstart_Bin);
      file = fopen(&v6, "wb");
      if ( file )
      {
        WriteToFile(&stage, 0x14u, 1u, file);
        fclose(file);
      }
      v4 = DebugOptsPtr;
      *(_DWORD *)DebugOptsPtr = stage;
      *(_DWORD *)(v4 + 4) = scroll;
      *(_DWORD *)(v4 + 8) = speed;
      *(_DWORD *)(v4 + 12) = power;
      *(_DWORD *)(v4 + 16) = life;
      EndDialog(hDlg, 1);
    }
    else if ( (unsigned __int16)wParam == 2 )
    {
      EndDialog(hDlg, 0);
    }
  }
  return 1;
}


