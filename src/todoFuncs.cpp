

#include <windows.h>
#include <math.h>
#include <defs.h>

#include <stdarg.h>

#define 
signed int GetTrg();
int GetKeyHeld();
int ClearTrg_(int a1);
int UpdateTrg(int a1);
signed int GetPlayerInput(char a1);
int SetBackgroundColor_();
NPCHAR *PutObject(int a1, NPCHAR *obj, int a3, int a4); 
int *GetNpcTable();
void *ResetEntities();
void *LoadPximgEntities();
int ActNpc();
int HitEntityMap();
NPCHAR *MapCollideEntityProc(NPCHAR *a1, int a2, int a3, int a4);
int PutNpChar2(int a1);
int PutNpChar(int a1);
int *CreateEntity(int type, int x, int y, int type2); 
NPCHAR *DamageNpChar(NPCHAR *o, int dmg); 
int UnusedGetNpcTblNext();
int CountNpChar(int a1);
int ClearReplaceNpChar(int a1, int a2);

int *GetShip();
void *ResetShip();
void SetInitialShipValues();
signed int ShipCrushProc();
signed int ActPowerUp(NPCHAR *a1); 
void *LoadPximgPlayerInit();
void *ActShipState(_DWORD *a1);
int *ActShipFlightIntro();
int *ActShipFlightExit();
int ActPlayerInput(_DWORD *a1);
int ShootBullet0();
int ShootBullet1();
signed int ShootBullet2();
int ShootBullet3();
int ShootBullet4();
int ShootBullet5();
int ShootBullet6();
int ShootBullet7();
int ShootBullet8();
signed int ShootBullet9(int a1);
signed int ShootBullet10();
int ShootBullet11();
int KillShip();
Ship *ShipStateEndingProc();
int HitShipMap();
NPCHAR *MapCollideShipProc(NPCHAR *a1, int a2, int a3, int a4);
unsigned int PutPlayerExtra(int a1);
int PutPlayer(int a1);
signed int SetSpeedPowerUp();
signed int SetLifePowerUp();
int SetSpeed(signed int a1);
int SetPowerUp(int a1);
void SetShipBoost();
int SetLife(int a1);
void SetShipInvincibility();
void SetShipEnding();
int LoadPximgCharactor();
int PutNumber(int a1, int x, int y, signed int value, char a5, signed int a6); 
int PutTextObject(int, int, int, char *, int, int); 
Bullet *HitNpCharBullet();
int *HitShipPowerup();
int HitMapGeneric(NPCHAR *o, int (*func)(int, int, int, int), int a3); 
signed int __stdcall DialogDebugStart(HWND hDlg, UINT uMsg, WPARAM wParam, LPARAM lParam);
void *LoadPximgEnemyName();
void *UnusedResetEndingText();
int ShowNextEndingText();
int EndingTextRunTimer();
void PutEndingText();
BOOL CheckEndingTextCount();
int PrepPxeve();
signed int ResetEntityStageTotal();
int LoadPxeve(int a1);
BOOL LoadPximgEnemy(int a1);
void ZeroEntityCount();
signed int SetStageEntities();
signed int SetStageEntitiesPartial();
void *DragEnable(HWND hWnd);
signed int DragFileProc(int a1, HDROP a2);
BOOL CheckDragFile();
CHAR *GetDragFile();
void *InitDragFile();
int InitGameAttr();
void *CheckGameCleared();

void CallClearCenterText();
int SetInReplay(int a1);
int SetInScoreAttack(int a1);
int Unused(int a1);
BOOL GetInReplay();
int GetInScoreAttack();
BOOL GetGameCleared();
signed int ChangeMusic(int a1);
signed int GameStart();
int GetCurrentStage();
int IncreaseLives();
signed int StartStage();
signed int InitStage();
int SetCheckpointScroll();
signed int CheckStageClear(int a1);
signed int ShipCrushProc2();
signed int ActStageState(int a1);
int WriteGameCleared();
void EndRecordPlayback();
int PutHUD(int a1);

signed int LoadGenericData();
int Game(HWND hWnd); 
int LoadPximg(int a1, int a2);
int CountFramePerSecond();
int PutFramePerSecond();
signed int Flip_SystemTask();
int SetReset(int a1);
int GetGameReset();
signed int Call_Escape();
signed int KeyConfigLoop(int a1, int joy); 
signed int ConfigKey(int a1);
signed int ConfigJoystick(int a1);
int PutKeyConfig(int a1, int a2, int a3, int a4);
int ModeEnding();
void EndingPrint(_DWORD, _DWORD, _DWORD);
int ModeAction(int a1);
signed int PauseLoop(int a1, int a2);
signed int RankingViewLoop();
int OpenRankingFile(void *); 
char *SetDefaultRankingNames(void *a1);
signed int sub_41BC20(int a1);
signed int sub_41BC90(int a1, int a2);
int PutRankingView(int a1, int a2, int a3);
signed int RankingLoop();
int WriteRankingFile(void *a1);
signed int sub_41C150(int a1, int a2);
void ResetRankingInput();
signed int RunRankingInput(int a1, int a2);
int PutRankingInput(int, char *); 
int GetCompileVersion(_DWORD *a1, _DWORD *a2, _DWORD *a3, _DWORD *a4);
int MenuLoop();
signed int message();
int __stdcall WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nShowCmd);
int ReadMainScreenMode();
signed int DrawStudioPixel();
int SetWindowAttr(HINSTANCE hInstance, int, int); 
int SetScreenMode(__int16 a1, int a2);
int __stdcall menu(HWND hWnd, UINT Msg, WPARAM wParam, LPARAM lParam); 
int MinimizeGame();
void *RestoreGame();
int OpenSoundVolume(HWND hwnd); 
UINT InitMenuItem(HWND hWnd);
FILE *SaveWindowSettings(HWND hWnd);
FILE *WriteScreenMode();
signed int ResetStage();
int GetStageHeight();
int LoadStage(int a1);
int PutMapParts(WindowAttr *window); 
int PutMapParts2(int a1);
int GetTileAttr(int x, int y); 
int GetTile(int x, int y); 
signed int ResetGameSurface_();
void ClearCenterText();
signed int FreeCenterText();
void *PutTextCenter(char *a1);
int PutTextBuffer(int a1);
int sub_41EC40();
void ResetRandom();
__int16 GetRandom(signed int max); 
signed int InitPlayRecord();
void FreePlayRecord();
void NewPlayRecord();
void ZeroPlayRecord();
signed int RecordPlayRecord(int a1);
int EndPlayRecord();
int ActPlayRecord();
BOOL CheckPlayRecordFlag();
int WritePlayRecord(char inScoreAttack, int stage, int score); 
void DeleteOldPlayRecord(int a1, unsigned int a2);
int ReadPlayRecord(char *, int); 
void *__thiscall sub_41F6D0(void *this);

int sub_41F720(int this);
int sub_41F760(void *this, unsigned int a2);
_DWORD *__thiscall sub_41F7B0(void *this, int a2);
int sub_41F820(int this);
void *__thiscall sub_41F860(int this, void *a2);
int sub_41F880(int this, int a2);
_DWORD *__thiscall sub_41F8A0(void *this, _DWORD *a1, int a2, int a3);
char sub_41F920(int this, unsigned int a2);
int sub_41F9A0(int this);
char *__stdcall sub_41FA10(void *a1, int a2, int a3);
void __noreturn sub_41FA40();

void *__thiscall sub_41FAD0(void *this, int a2);

void *__thiscall sub_41FB50(void *this, char a2);
void sub_41FB80(int this);
void sub_41FBE0(void *this);
void *__thiscall sub_41FC00(void *this, char a2);
void *__thiscall sub_41FC30(void *this, int a2);
_BYTE *__thiscall sub_41FC80(void *this);

void *__thiscall sub_41FCC0(void *this, int a2, unsigned int a3, unsigned int a4);

_BYTE *__thiscall sub_41FDA0(int this, char a2, size_t a3);

void *__thiscall sub_41FE50(void *this, char a2);

void *__thiscall sub_41FE80(void *this, char a2);
_DWORD *__thiscall sub_41FED0(void *this, _DWORD *a2, int a3);

void *__thiscall sub_41FF30(void *this, int a2);
_DWORD *__thiscall sub_41FFA0(void *this, char *a2);
int sub_41FFE0(int this, unsigned int a2, unsigned int a3);
void *sub_420070(void *a1, void *a2, size_t a3);

_BYTE *__thiscall sub_4200B0(int this, int a2);

BOOL sub_420100(void *this, unsigned int a2, char a3);

int __stdcall sub_420210(int a1, int a2);
void *__thiscall sub_420240(void *this, int a2, unsigned int a3, int a4);
void __noreturn sub_420580();

void sub_420610(void *this);
void *__thiscall sub_420630(void *this, char a2);
void *__stdcall sub_420690(int a1);

void *__thiscall sub_4206D0(void *this, int a2);
int sub_4206F0(void *this, _DWORD *a2);
_DWORD *__thiscall sub_420760(_DWORD *this, char *a2);
_BYTE *__thiscall sub_4207F0(_DWORD *this, int a2, size_t a3);

signed int sub_420960();

int sub_4209B0(void *this, _DWORD *a2);
_DWORD *__thiscall sub_4209D0(_DWORD *this, void *a2, size_t a3);
void *__stdcall sub_420A50(SIZE_T a1);

bool sub_420AA0(_DWORD *this, unsigned int a2);
void *sub_420AE0(void *a1, int a2, int a3);
int sub_420B20(int a1, int a2);
void *__stdcall sub_420B60(int a1, int a2, void *a3);
int sub_420B90(int a1, int a2, int a3);
int sub_420BC0(int a1, int a2, int a3);
void *sub_420C00(int a1);

char __fastcall GetByte3(int a1);
void *sub_420C50(void *a1, int a2, int a3);
int sub_420CF0(int a1, int a2);
void *sub_420D20(int a1, int a2, void *a3);
int sub_420D60(int a1, int a2, int a3);
_DWORD *__stdcall sub_420DA0(void *a1, int a2);
void __stdcall CallsDoNothing(int a1);
void *sub_420DE0(int a1, int a2, void *a3);
_DWORD *sub_420E90(void *a1, int a2);

void DoNothing(int a1);
signed int LoadPximgSymbol();
signed int ResetScore();
int GetScore();
int SetScore(int a1);
int AddScore(int a1);
int PutScore(int a1, int x, int y); 
int SetDefaultStageScroll();
int SetStageScroll(int a1);
int SetScrollSpeed(int a1);
int SetStageXOffset(int a1);
int GetCheckpointScrollValue();
int GetStageXOffset();
int GetStageScroll();
int AlignStageScroll(NPCHAR *a1); 
int ActStageScroll();
_DWORD *AddStageXOScroll(_DWORD *a1, _DWORD *a2);
_DWORD *SubStageXOScroll(_DWORD *a1, _DWORD *a2);
signed int LoadPximgScreenEffect();
void *EndingInitFade();
void ResetFade();
void SetFadeActive();
BOOL CheckFadeEnd();
int SetFadeWhiteActive(int a1, int a2);
BOOL CheckFadeWhiteEnd();
void RecordEndFadeWhite();
int ActFade();
int PutFade(int a1);
void ClearLoopSound();
int StopLoopSound2();
BOOL LoadSound(int a1, int a2);

int PlaySound(int a1);

int PlayLoopSound(signed int a1);
int StopLoopSound(int a1);
int PauseLoopSound();
int ResumeLoopSound();
int SetSoundDisabled(int a1);
int SetGameDelay(int a1);
BOOL GetGameDelayed();
void InitTriangleTable();
int GetSin(unsigned __int8 a1);
int GetCos(unsigned __int8 a1);
char GetArktan(int x, int y, char a3); 
void CallReturnCos(float a1);
double ReturnCos(float a1);
void CallReturnSin(float a1);
double ReturnSin(float a1);
int OpenResource_(HMODULE hModule, LPCSTR lpName, LPCSTR lpType, int a4);
int PixelRead(int p, size_t size, int num, int _b_file); 
signed int sub_4220D0(int a1, __int32 a2, int a3);
int CloseResource_(int a1);
signed int VariableLengthCheck(unsigned int a1);
signed int VariableLengthWrite(unsigned int val, FILE *a2, _DWORD *a3); 
signed int VariableLengthRead(_DWORD *p, int a2); 
int InitDirectInput(HINSTANCE hinst, int); 
signed int sub_422730(int a1);
signed int sub_422800(void *this, int a2, int a3);
int ReleaseDirectInput();
signed int JoystickProc_(int a1);
signed int sub_422AA0(int a1);
signed int sub_422AF0();
char *ClearSurface(signed int a1);
void **ReleaseSurface(void **a1);
int ClearSurfaceTbl();
int SetRenderOffset(int a1, int a2);
int SetFullscreenRenderPos();
signed int SetCooperativeMode(int a1);
int InitDirectDraw(int, char *, int, int); 
HRESULT EndDirectDraw(int a1);
signed int InitMainSurface(int a1, int a2, int a3, int a4);
int ReleaseSurfaceA();
signed int Flip_Screen();
int MakeSurface_Pximg(char *, int, int, int); 
int AllocSurface(int, size_t); 
signed int MakeSurface(int a1, int a2, int a3, int a4);
int PreparePximg(int, HGDIOBJ h, int wSrc, int hSrc); 
int DecodePximg(PximgDecodeInfo *info, int img_height, __int16 hash_a, __int16 hash_b); 
__int16 PximgHashShuffle(PximgDecodeInfo *a1); 
int ReleasePximgDecoder(int a1);
signed int InitSurface_(int a1, int a2, signed int a3, int a4);
int MakeSurface_Generic(char *, int, int); 
RECT *MagnifyRect(RECT *a1);
int PutRect(int x, int y, RECT *rect, signed int surf_no); 
int PutBitmapPause_(signed int a1);
int PutBitmap3(RECT *rcView, int x, int y, RECT *rect, signed int surf_no); 
int PutNumber2_(int a1, int a2, int a3, signed int a4, signed int a5);
int PutBackground(int a1, int a2);
int Unused2(int a1, int a2, int a3);
int RenderToSurface_(int a1, int a2, signed int a3);
int sub_424150(int a1, int a2, int a3);
int SetSurfaceColor(COLORREF color); 
signed int GetSurfaceColor(int a1);
HFONT InitFont(LPCSTR pszFaceName, char a2, int cHeight);
BOOL CallDeleteObject();
signed int DoNothing2(int a1);
int sub_4245E0();
signed int ResetSurfaceTbl(int a1, int a2);
int AssignDirectSound(int a1);
signed int UnusedInitDirectSound(int a1);
int sub_424A30();
signed int Unused3Sound(const CHAR *lpName, const CHAR *lpType, signed int a3);
void **sub_424C60(void **a1);
int sub_424C90(LPCSTR lpName, LPCSTR lpType, void *, int, int); 
int sub_424EB0(int, size_t); 
signed int sub_424EF0(const CHAR *lpName, const CHAR *lpType, int a3, int a4, int a5, signed int a6);
int sub_4250A0(LPCSTR lpName, LPCSTR lpType, void *, int, int, int, int, int); 
signed int sub_4251F0(signed int a1);
int sub_425250(signed int a1);
int startloopsoundproc_(signed int a1);
int stoploopsoundproc_(signed int a1);

void **ReleaseEntities(_DWORD *a1);
void **ReleaseEntityPtr(void **a1);
signed int Unused4(_DWORD *a1, int a2);
int AllocEntity(int, size_t); 
signed int ReadPxeve(int ptr, int res?); 
signed int Unused5(int a1, FILE *a2);
void *ResetInput();
HWND KeyCapture_(HWND hWnd, int a2, int a3);
int KeyTrigUpdate_();
BOOL GetKeyHeld_(int a1);
BOOL GetKeyCode(int a1);
BOOL Unused6();
BOOL Unused7();
BOOL Unused8();
BOOL Unused9();
int SetFullscreenWindowPos(HWND hWnd); 
int SetPtrTempGuxt(int a1);
int SetWindowPosRect(HWND hWnd, int, int); 
int SaveWindowRect(HWND hWnd, int); 

BOOL CloseMutex(int this);
int StartMutex(int this, LPCSTR lpName, LPCSTR a3);
HANDLE ShowExistingWindow(LPCSTR lpName);
int StartMutex2(int this, LPCSTR lpName, LPCSTR a3, int a4);
int sprintf_(int arg0, char *arg4, ...);
BOOL sub_426400(HWND a1, CHAR *a2, const CHAR *a3, const CHAR *a4, const CHAR *a5, const CHAR *a6);
BOOL Unused12(HWND a1, CHAR *a2, const CHAR *a3, const CHAR *a4, const CHAR *a5);
int SetUnusedPtrTempGuxt(int a1);
int Unused13(LPCSTR pszPath, int a2);
int Unused14(char *a1, int a2);
int Unused15(int a1);
HRESULT Unused16(CHAR *pszPath);
int memset12bytes(void *); 
void *Unused10(int a1);
signed int Unused11(int a1, signed int a2, signed int a3, char a4);
int sub_4269B0(int, size_t); 
void **FreeStageAttr(void **a1);
void **ReleaseStageAttr(int a1);
int LoadStageAttr(int a1, int a2);
int pxtnPulse_Noise::Fix(int a1);
void PxNoise_FixUnit(int a1);
int DecodePtnoise_(void **a1, int a2, int a3, signed int a4, int a5);
int pxtnMem_zero_alloc(int pp, size_t byte_size); 
int sub_427630();
void **pxtnMem_free(void **a1);
int pxtnPulse_NoiseBuilder::Init();
void pxtnPulse_NoiseBuilder::_random_reset();
__int16 pxtnPulse_NoiseBuilder::_random_get();
int sub_427CD0(int a1, int a2, signed int a3);
void sub_427DC0(int a1, double a2);
int pxtnPulse_Noise::write(FILE *a1, int *p_add, int a3); 
int WriteOscillator(pxNOISEDESIGN_OSCILLATOR *p_osc, FILE *a2, _DWORD *p_add); 
signed int MakeFlags(int a1);
int ReadPtnoise_(int, void *, int); 
int pxtnNoise_zero_alloc(int, size_t); 
signed int ReadPtnoise2_(int a1, int a2);
void *pxtnPulse_Noise::Release(void *a1);
void **pxtnNoise_free(void **a1);
signed int pxtnPulse_Noise::Allocate(_DWORD *a1, int a2, int a3);
signed int Unused19(_DWORD *a1, int a2);
void pxtnPulse_Frequency::Init();
double pxtnPulse_Frequency::_GetDivideOctaveRate(int divi); 
double sub_428C20(int a1);
int pxtnPulse_Oscillator::ReadyGetSample(int a1, int a2, int a3, int a4, int a5);
double pxtnPulse_Oscillator::GetOneSample_Overtone(signed int index); 
double Unused20(int a1);




size_t WriteToFile(void *a1, size_t a2, size_t a3, FILE *a4);

size_t ReadFromFile(void *a1, size_t a2, size_t a3, FILE *a4);

void nullsub_1();

int Unused21(int a1);





int sub_42A3B8(int this);
void sub_42A450(int this);
exception *__thiscall Unused23(exception *this, char *a2);
_DWORD *__thiscall Unused24(_DWORD *this, int a2);
void sub_42A4A4(void *this);
exception *__thiscall sub_42A4AF(exception *this, char *a2);
_DWORD *__thiscall sub_42A4C8(_DWORD *this, int a2);
void sub_42A4E0(int this);
exception *__thiscall Unused25(exception *this, char *a2);
_DWORD *__thiscall Unused26(_DWORD *this, int a2);
void sub_42A51B(void *this);
void *__thiscall sub_42A526(void *this, char a2);
void *__thiscall sub_42A561(void *this, char a2);
void *__thiscall sub_42A57D(void *this, char a2);
void *__thiscall sub_42A599(void *this, char a2);
char *__thiscall sub_42A66D(char *this);
void *__thiscall sub_42A671(void *this, int a2);
void *__thiscall sub_42A67C(void *this, int a2);

void j__free(void *);





int sub_42BB2F(int a1);

int sub_42BB4B(int a1);



int sub_42BFAA();
void **sub_42BFB3();






HANDLE sub_42DDF3();

void __noreturn sub_42DEB8();

int sub_42EF36();

void sub_42F2B2();
void nullsub_2();


void __noreturn sub_42FEB3();

int sub_42FF7A();
LPTOP_LEVEL_EXCEPTION_FILTER sub_42FF8D();






void sub_430F5B();
void sub_430F9F(); 




int sub_43283D(WORD CharType); 

int sub_432B63(int a1, int a2);
int sub_432B79(int a1, int a2);
int sub_432C0B(int a1, int a2);
int sub_432C86(int a1, int a2);



int sub_433364();
void *sub_43336A();
int sub_433501();

int sub_434646(char a1);

int sub_434864();

int sub_4348DF();

int sub_434972(WORD CharType, int a2);

int sub_4356F4();

size_t sub_43661D(char *a1, size_t a2, char *a3, struct tm *a4);
void **sub_436638();

size_t sub_437328();
int sub_437379();



int sub_43870F();
signed int sub_438A32(signed int a1, int a2);


char *sub_439D59(char *a1);




void __noreturn sub_43A924();
void __noreturn sub_43A964();






int sub_43AD82(struct EHExceptionRecord *a1, struct EHRegistrationNode *a2, struct _CONTEXT *a3, void *a4);

int sub_43AD94(struct EHExceptionRecord *a1, struct EHRegistrationNode *a2, struct _CONTEXT *a3, void *a4);












































signed int GetTrg()
{
  signed int v1; 
  int v2; 
  int v3; 
  int v4; 
  int v5; 
  int v6; 

  v1 = 0;
  isKeyHeld = 0;
  if ( GetKeyHeld_((unsigned __int8)gKeyLeft) )
    v1 = 16;
  if ( GetKeyHeld_((unsigned __int8)gKeyRight) )
    v1 |= 0x20u;
  if ( GetKeyHeld_((unsigned __int8)gKeyUp) )
    v1 |= 0x40u;
  if ( GetKeyHeld_((unsigned __int8)gKeyDown) )
    v1 |= 0x80u;
  if ( GetKeyHeld_((unsigned __int8)gKeyShoot) )
    v1 |= 1u;
  if ( GetKeyHeld_((unsigned __int8)gKeyPause) )
    v1 |= 2u;
  if ( v1 )
    isKeyHeld = 1;
  if ( JoystickProc_((int)&v2) )
  {
    if ( v2 )
      v1 |= 0x10u;
    if ( v3 )
      v1 |= 0x20u;
    if ( v4 )
      v1 |= 0x40u;
    if ( v5 )
      v1 |= 0x80u;
    if ( v6 & (1 << gJoyShoot) )
      v1 |= 1u;
    if ( v6 & (1 << gJoyPause) )
      v1 |= 2u;
  }
  return v1;
}



int GetKeyHeld()
{
  return isKeyHeld;
}

int ClearTrg_(int a1)
{
  int result; 

  ResetInput();
  *(_DWORD *)a1 = GetTrg();
  result = a1;
  *(_DWORD *)(a1 + 8) = *(_DWORD *)a1;
  *(_DWORD *)(a1 + 4) = 0;
  return result;
}
int UpdateTrg(int a1)
{
  int result; 

  *(_DWORD *)(a1 + 4) = *(_DWORD *)(a1 + 8) ^ *(_DWORD *)a1;
  *(_DWORD *)(a1 + 4) &= *(_DWORD *)a1;
  result = a1;
  *(_DWORD *)(a1 + 8) = *(_DWORD *)a1;
  return result;
}
signed int GetPlayerInput(char a1)
{
  signed int result; 

  if ( a1 & 0x10 && a1 & 0x40 )
  {
    result = 5;
  }
  else if ( a1 & 0x20 && a1 & 0x40 )
  {
    result = 6;
  }
  else if ( a1 & 0x10 && a1 & 0x80 )
  {
    result = 7;
  }
  else if ( a1 & 0x20 && a1 & 0x80 )
  {
    result = 8;
  }
  else if ( a1 & 0x10 )
  {
    result = 1;
  }
  else if ( a1 & 0x20 )
  {
    result = 2;
  }
  else if ( a1 & 0x40 )
  {
    result = 3;
  }
  else if ( a1 & 0x80 )
  {
    result = 4;
  }
  else
  {
    result = 0;
  }
  return result;
}
int SetBackgroundColor_()
{
  int result; 

  result = SetSurfaceColor(160u);
  dword_442C54 = result;
  return result;
}


void *__thiscall sub_41F6D0(void *this)
{
  void *v2; 
  void *v3; 

  v3 = this;
  v2 = this;
  unknown_libname_10(&v2);
  sub_41FE80(v3, (char)v2);
  sub_41F920((int)v3, 0);
  return v3;
}
int sub_41F720(int this)
{
  int v2; 

  if ( *(_DWORD *)(this + 4) )
    v2 = (*(_DWORD *)(this + 8) - *(_DWORD *)(this + 4)) / 12;
  else
    v2 = 0;
  return v2;
}
int sub_41F760(void *this, unsigned int a2)
{
  void *v2; 
  _DWORD *v3; 
  void *v5; 
  char v6; 
  char v7; 

  v5 = this;
  if ( sub_41F720((int)this) <= a2 )
    sub_41FA40();
  v2 = sub_41F860((int)v5, &v7);
  v3 = sub_41FED0(v2, &v6, a2);
  return unknown_libname_11(v3);
}
_DWORD *__thiscall sub_41F7B0(void *this, int a2)
{
  unsigned int v2; 
  _DWORD *result; 
  int *v4; 
  void *v5; 
  char v6; 
  char v7; 

  v5 = this;
  v2 = sub_41F720((int)this);
  if ( v2 >= sub_41F820((int)v5) )
  {
    v4 = (int *)sub_41F880((int)v5, (int)&v7);
    result = sub_41F8A0(v5, &v6, *v4, a2);
  }
  else
  {
    result = sub_41FA10(*((void **)v5 + 2), 1, a2);
    *((_DWORD *)v5 + 2) = result;
  }
  return result;
}
int sub_41F820(int this)
{
  int v2; 

  if ( *(_DWORD *)(this + 4) )
    v2 = (*(_DWORD *)(this + 12) - *(_DWORD *)(this + 4)) / 12;
  else
    v2 = 0;
  return v2;
}
void *__thiscall sub_41F860(int this, void *a2)
{
  unknown_libname_20(a2, *(_DWORD *)(this + 4));
  return a2;
}
int sub_41F880(int this, int a2)
{
  unknown_libname_20((void *)a2, *(_DWORD *)(this + 8));
  return a2;
}
_DWORD *__thiscall sub_41F8A0(void *this, _DWORD *a1, int a2, int a3)
{
  _DWORD *v4; 
  int v5; 
  void *v6; 
  int v8; 
  void *v9; 
  char v10; 
  char v11; 
  int v12; 

  v9 = this;
  if ( sub_41F720((int)this) )
  {
    v4 = sub_41F860((int)v9, &v11);
    v8 = sub_4206F0(&a2, v4);
  }
  else
  {
    v8 = 0;
  }
  v12 = v8;
  sub_420240(v9, a2, 1u, a3);
  v5 = v12;
  v6 = sub_41F860((int)v9, &v10);
  sub_41FED0(v6, a1, v5);
  return a1;
}
char sub_41F920(int this, unsigned int a2)
{
  char result; 
  int v3; 

  v3 = this;
  *(_DWORD *)(this + 4) = 0;
  *(_DWORD *)(this + 8) = 0;
  *(_DWORD *)(this + 12) = 0;
  if ( a2 )
  {
    if ( unknown_libname_16((void *)this) < a2 )
      sub_420580();
    *(_DWORD *)(v3 + 4) = sub_420690(a2);
    *(_DWORD *)(v3 + 8) = *(_DWORD *)(v3 + 4);
    *(_DWORD *)(v3 + 12) = *(_DWORD *)(v3 + 4) + 12 * a2;
    result = 1;
  }
  else
  {
    result = 0;
  }
  return result;
}
int sub_41F9A0(int this)
{
  int result; 
  int v2; 

  v2 = this;
  if ( *(_DWORD *)(this + 4) )
  {
    sub_420210(*(_DWORD *)(this + 4), *(_DWORD *)(this + 8));
    unknown_libname_19(*(void **)(v2 + 4), (*(_DWORD *)(v2 + 12) - *(_DWORD *)(v2 + 4)) / 12);
  }
  *(_DWORD *)(v2 + 4) = 0;
  *(_DWORD *)(v2 + 8) = 0;
  result = v2;
  *(_DWORD *)(v2 + 12) = 0;
  return result;
}
char *__stdcall sub_41FA10(void *a1, int a2, int a3)
{
  sub_420AE0(a1, a2, a3);
  return (char *)a1 + 12 * a2;
}
void __noreturn sub_41FA40()
{
  char v0; 
  char v1; 
  int v2; 

  sub_41FFA0(&v0, "invalid vector<T> subscript");
  v2 = 0;
  unknown_libname_6(&v1, (int)&v0);
  _CxxThrowException(&v1, &unk_43F298);
}

void *__thiscall sub_41FAD0(void *this, int a2)
{
  void *v2; 

  v2 = this;
  sub_42A3B8((int)this);
  *(_DWORD *)v2 = &off_43EF28;
  sub_41FC30((char *)v2 + 12, a2);
  return v2;
}

void *__thiscall sub_41FB50(void *this, char a2)
{
  void *v3; 

  v3 = this;
  sub_41FB80((int)this);
  if ( a2 & 1 )
    j__free(v3);
  return v3;
}
void sub_41FB80(int this)
{
  int v1; 

  v1 = this;
  *(_DWORD *)this = &off_43EF28;
  sub_41FC80((void *)(this + 12));
  sub_42A450(v1);
}

void sub_41FBE0(void *this)
{
  *(_DWORD *)this = &off_43EF40;
  sub_41FB80((int)this);
}

void *__thiscall sub_41FC00(void *this, char a2)
{
  void *v3; 

  v3 = this;
  sub_41FBE0(this);
  if ( a2 & 1 )
    j__free(v3);
  return v3;
}
void *__thiscall sub_41FC30(void *this, int a2)
{
  void *v3; 
  void *v4; 

  v4 = this;
  v3 = this;
  unknown_libname_9(&v3, a2);
  sub_41FE50(v4, (char)v3);
  sub_41FDA0((int)v4, 0, 0);
  sub_41FCC0(v4, a2, 0, 0xFFFFFFFF);
  return v4;
}
_BYTE *__thiscall sub_41FC80(void *this)
{
  return sub_41FDA0((int)this, 1, 0);
}
void *__thiscall sub_41FCC0(void *this, int a2, unsigned int a3, unsigned int a4)
{
  void *v4; 
  void *v5; 
  void *v7; 
  unsigned int v8; 

  v7 = this;
  if ( unknown_libname_13(a2) < a3 )
    sub_43A924();
  v8 = unknown_libname_13(a2) - a3;
  if ( a4 < v8 )
    v8 = a4;
  if ( v7 == (void *)a2 )
  {
    sub_41FFE0((int)v7, v8 + a3, 0xFFFFFFFF);
    sub_41FFE0((int)v7, 0, a3);
  }
  else if ( (unsigned __int8)sub_420100(v7, v8, 0) )
  {
    v4 = (void *)(a3 + unknown_libname_8(a2));
    v5 = (void *)unknown_libname_14((int)v7);
    std::char_traits<char>::copy(v5, v4, v8);
    sub_4200B0((int)v7, v8);
  }
  return v7;
}
_BYTE *__thiscall sub_41FDA0(int this, char a2, size_t a3)
{
  int v4; 
  void *v5; 

  v4 = this;
  if ( a2 && *(_DWORD *)(this + 24) >= 0x10u )
  {
    v5 = *(void **)(this + 4);
    if ( a3 )
      std::char_traits<char>::copy((void *)(this + 4), v5, a3);
    unknown_libname_15(v5, *(_DWORD *)(v4 + 24) + 1);
  }
  *(_DWORD *)(v4 + 24) = 15;
  return sub_4200B0(v4, a3);
}
void *__thiscall sub_41FE50(void *this, char a2)
{
  void *v2; 

  v2 = this;
  unknown_libname_9(this, (int)&a2);
  return v2;
}
void *__thiscall sub_41FE80(void *this, char a2)
{
  void *v2; 

  v2 = this;
  unknown_libname_18(this, (int)&a2);
  return v2;
}
_DWORD *__thiscall sub_41FED0(void *this, _DWORD *a2, int a3)
{
  int v4; 

  v4 = *(_DWORD *)this;
  *a2 = *(_DWORD *)sub_4206D0(&v4, a3);
  return a2;
}
void *__thiscall sub_41FF30(void *this, int a2)
{
  void *v2; 

  v2 = this;
  exception::exception(a2);
  *(_DWORD *)v2 = &off_43EF28;
  sub_41FC30((char *)v2 + 12, a2 + 12);
  return v2;
}


_DWORD *__thiscall sub_41FFA0(void *this, char *a2)
{
  void *v3; 
  _DWORD *v4; 

  v4 = this;
  v3 = this;
  unknown_libname_24(&v3);
  sub_41FE50(v4, (char)v3);
  sub_41FDA0((int)v4, 0, 0);
  sub_420760(v4, a2);
  return v4;
}
int sub_41FFE0(int this, unsigned int a2, unsigned int a3)
{
  size_t v3; 
  void *v4; 
  int v5; 
  int v7; 

  v7 = this;
  if ( *(_DWORD *)(this + 20) < a2 )
    sub_43A924();
  if ( *(_DWORD *)(this + 20) - a2 < a3 )
    a3 = *(_DWORD *)(this + 20) - a2;
  if ( a3 )
  {
    v3 = *(_DWORD *)(this + 20) - a2 - a3;
    v4 = (void *)(a3 + a2 + unknown_libname_14(this));
    v5 = unknown_libname_14(v7);
    sub_420070((void *)(a2 + v5), v4, v3);
    sub_4200B0(v7, *(_DWORD *)(v7 + 20) - a3);
  }
  return v7;
}
void *sub_420070(void *a1, void *a2, size_t a3)
{
  return memcpy_0(a1, a2, a3);
}
_BYTE *__thiscall sub_4200B0(int this, int a2)
{
  int v2; 
  char v4; 

  v4 = 0;
  *(_DWORD *)(this + 20) = a2;
  v2 = unknown_libname_14(this);
  return std::char_traits<char>::assign((_BYTE *)(a2 + v2), &v4);
}
BOOL sub_420100(void *this, unsigned int a2, char a3)
{
  _DWORD *v4; 

  v4 = this;
  if ( unknown_libname_46() < a2 )
    sub_43A964();
  if ( v4[6] >= a2 )
  {
    if ( a3 && a2 < 0x10 )
    {
      if ( a2 >= v4[5] )
        sub_41FDA0((int)v4, 1, v4[5]);
      else
        sub_41FDA0((int)v4, 1, a2);
    }
    else if ( !a2 )
    {
      sub_4200B0((int)v4, 0);
    }
  }
  else
  {
    sub_4207F0(v4, a2, v4[5]);
  }
  return a2 > 0;
}
int __stdcall sub_420210(int a1, int a2)
{
  return sub_420B20(a1, a2);
}
void *__thiscall sub_420240(void *this, int a2, unsigned int a3, int a4)
{
  void *result; 
  int v5; 
  int v6; 
  unsigned int v7; 
  int v8; 
  int v9; 
  int v10; 
  char *v11; 
  void *v12; 
  int v13; 
  void *v14; 
  int v15; 
  void *v16; 
  void *v17; 
  int v18; 
  int v19; 
  int v20; 
  int v21; 
  int *v22; 
  int v23; 
  int v24; 

  v22 = &v10;
  v14 = this;
  v19 = *(_DWORD *)a4;
  v20 = *(_DWORD *)(a4 + 4);
  v21 = *(_DWORD *)(a4 + 8);
  result = (void *)sub_41F820((int)this);
  v18 = (int)result;
  if ( a3 )
  {
    v5 = sub_41F720((int)v14);
    if ( unknown_libname_16(v14) - v5 < a3 )
      sub_420580();
    v6 = sub_41F720((int)v14);
    if ( v18 >= a3 + v6 )
    {
      if ( (*((_DWORD *)v14 + 2) - a2) / 12 >= a3 )
      {
        v15 = *((_DWORD *)v14 + 2);
        *((_DWORD *)v14 + 2) = sub_420B60(v15 - 12 * a3, v15, *((void **)v14 + 2));
        sub_420BC0(a2, v15 - 12 * a3, v15);
        result = (void *)sub_420B90(a2, a2 + 12 * a3, (int)&v19);
      }
      else
      {
        sub_420B60(a2, *((_DWORD *)v14 + 2), (void *)(a2 + 12 * a3));
        v23 = 2;
        sub_41FA10(*((void **)v14 + 2), a3 - (*((_DWORD *)v14 + 2) - a2) / 12, (int)&v19);
        v23 = -1;
        *((_DWORD *)v14 + 2) += 12 * a3;
        result = (void *)sub_420B90(a2, *((_DWORD *)v14 + 2) - 12 * a3, (int)&v19);
      }
    }
    else
    {
      v7 = (unsigned int)v18 >> 1;
      v8 = unknown_libname_16(v14);
      if ( v8 - v7 >= v18 )
        v13 = v18 + ((unsigned int)v18 >> 1);
      else
        v13 = 0;
      v18 = v13;
      v9 = sub_41F720((int)v14);
      if ( v18 < a3 + v9 )
        v18 = a3 + sub_41F720((int)v14);
      v16 = sub_420690(v18);
      v17 = v16;
      v23 = 0;
      v12 = sub_420B60(*((_DWORD *)v14 + 1), a2, v16);
      v17 = v12;
      v11 = sub_41FA10(v12, a3, (int)&v19);
      v17 = v11;
      sub_420B60(a2, *((_DWORD *)v14 + 2), v11);
      v23 = -1;
      v24 = a3 + sub_41F720((int)v14);
      if ( *((_DWORD *)v14 + 1) )
      {
        sub_420210(*((_DWORD *)v14 + 1), *((_DWORD *)v14 + 2));
        unknown_libname_19(*((void **)v14 + 1), (*((_DWORD *)v14 + 3) - *((_DWORD *)v14 + 1)) / 12);
      }
      *((_DWORD *)v14 + 3) = (char *)v16 + 12 * v18;
      *((_DWORD *)v14 + 2) = (char *)v16 + 12 * v24;
      result = v16;
      *((_DWORD *)v14 + 1) = v16;
    }
  }
  return result;
}
void __noreturn sub_420580()
{
  char v0; 
  char v1; 
  int v2; 

  sub_41FFA0(&v0, "vector<T> too long");
  v2 = 0;
  unknown_libname_17(&v1, (int)&v0);
  _CxxThrowException(&v1, &unk_43F3E8);
}

void sub_420610(void *this)
{
  *(_DWORD *)this = &off_43EF34;
  sub_41FB80((int)this);
}

void *__thiscall sub_420630(void *this, char a2)
{
  void *v3; 

  v3 = this;
  sub_420610(this);
  if ( a2 & 1 )
    j__free(v3);
  return v3;
}
void *__stdcall sub_420690(int a1)
{
  return sub_420C00(a1);
}
void *__thiscall sub_4206D0(void *this, int a2)
{
  *(_DWORD *)this += 12 * a2;
  return this;
}
int sub_4206F0(void *this, _DWORD *a2)
{
  int v3; 

  v3 = *(_DWORD *)this;
  return sub_4209B0(&v3, a2);
}
_DWORD *__thiscall sub_420760(_DWORD *this, char *a2)
{
  _DWORD *v2; 
  size_t v3; 

  v2 = this;
  v3 = unknown_libname_23(a2);
  return sub_4209D0(v2, a2, v3);
}
_BYTE *__thiscall sub_4207F0(_DWORD *this, int a2, size_t a3)
{
  int v3; 
  void *v4; 
  int v6; 
  void *v7; 
  _DWORD *v8; 
  unsigned int v9; 
  void *v10; 
  int *v11; 
  int v12; 

  v11 = &v6;
  v8 = this;
  v9 = a2 | 0xF;
  if ( unknown_libname_46() >= (a2 | 0xFu) )
  {
    if ( v9 / 3 < v8[6] >> 1 )
    {
      v3 = v8[6] >> 1;
      if ( v8[6] <= (unsigned int)(unknown_libname_46() - v3) )
        v9 = v8[6] + (v8[6] >> 1);
    }
  }
  else
  {
    v9 = a2;
  }
  v12 = 0;
  v7 = sub_420A50(v9 + 1);
  v10 = v7;
  v12 = -1;
  if ( a3 )
  {
    v4 = (void *)unknown_libname_14((int)v8);
    std::char_traits<char>::copy(v10, v4, a3);
  }
  sub_41FDA0((int)v8, 1, 0);
  v8[1] = v10;
  v8[6] = v9;
  return sub_4200B0((int)v8, a3);
}
signed int sub_420960()
{
  return 357913941;
}
int sub_4209B0(void *this, _DWORD *a2)
{
  return (*(_DWORD *)this - *a2) / 12;
}
_DWORD *__thiscall sub_4209D0(_DWORD *this, void *a2, size_t a3)
{
  int v3; 
  _DWORD *result; 
  void *v5; 
  _DWORD *v6; 

  v6 = this;
  if ( sub_420AA0(this, (unsigned int)a2) )
  {
    v3 = unknown_libname_14((int)v6);
    result = sub_41FCC0(v6, (int)v6, (unsigned int)a2 - v3, a3);
  }
  else
  {
    if ( (unsigned __int8)sub_420100(v6, a3, 0) )
    {
      v5 = (void *)unknown_libname_14((int)v6);
      std::char_traits<char>::copy(v5, a2, a3);
      sub_4200B0((int)v6, a3);
    }
    result = v6;
  }
  return result;
}
void *__stdcall sub_420A50(SIZE_T a1)
{
  return unknown_libname_26(a1);
}
bool sub_420AA0(_DWORD *this, unsigned int a2)
{
  _DWORD *v3; 

  v3 = this;
  return a2 >= unknown_libname_14((int)this) && v3[5] + unknown_libname_14((int)v3) > a2;
}
void *sub_420AE0(void *a1, int a2, int a3)
{
  GetByte3((int)&a1);
  return sub_420C50(a1, a2, a3);
}
int sub_420B20(int a1, int a2)
{
  GetByte3((int)&a1);
  return sub_420CF0(a1, a2);
}
void *__stdcall sub_420B60(int a1, int a2, void *a3)
{
  return sub_420D20(a1, a2, a3);
}
int sub_420B90(int a1, int a2, int a3)
{
  int result; 

  while ( a1 != a2 )
  {
    *(_DWORD *)a1 = *(_DWORD *)a3;
    *(_DWORD *)(a1 + 4) = *(_DWORD *)(a3 + 4);
    *(_DWORD *)(a1 + 8) = *(_DWORD *)(a3 + 8);
    result = a1 + 12;
    a1 += 12;
  }
  return result;
}
int sub_420BC0(int a1, int a2, int a3)
{
  GetByte3((int)&a1);
  return sub_420D60(a1, a2, a3);
}
void *sub_420C00(int a1)
{
  return operator new(12 * a1);
}

char __fastcall GetByte3(int a1)
{
  return BYTE3(a1);
}
void *sub_420C50(void *a1, int a2, int a3)
{
  void *result; 
  int v4; 
  void *v5; 
  int *v6; 
  int v7; 

  v6 = &v4;
  result = a1;
  v5 = a1;
  v7 = 0;
  while ( a2 )
  {
    result = sub_420DA0(a1, a3);
    --a2;
    a1 = (char *)a1 + 12;
  }
  return result;
}
int sub_420CF0(int a1, int a2)
{
  int result; 

  while ( a1 != a2 )
  {
    CallsDoNothing(a1);
    result = a1 + 12;
    a1 += 12;
  }
  return result;
}
void *sub_420D20(int a1, int a2, void *a3)
{
  GetByte3((int)&a1);
  return sub_420DE0(a1, a2, a3);
}
int sub_420D60(int a1, int a2, int a3)
{
  while ( a1 != a2 )
  {
    a2 -= 12;
    a3 -= 12;
    *(_DWORD *)a3 = *(_DWORD *)a2;
    *(_DWORD *)(a3 + 4) = *(_DWORD *)(a2 + 4);
    *(_DWORD *)(a3 + 8) = *(_DWORD *)(a2 + 8);
  }
  return a3;
}
_DWORD *__stdcall sub_420DA0(void *a1, int a2)
{
  return sub_420E90(a1, a2);
}
void __stdcall CallsDoNothing(int a1)
{
  DoNothing(a1);
}
void *sub_420DE0(int a1, int a2, void *a3)
{
  int v4; 
  void *v5; 
  int *v6; 
  int v7; 

  v6 = &v4;
  v5 = a3;
  v7 = 0;
  while ( a1 != a2 )
  {
    sub_420DA0(a3, a1);
    a3 = (char *)a3 + 12;
    a1 += 12;
  }
  return a3;
}
_DWORD *sub_420E90(void *a1, int a2)
{
  _DWORD *result; 
  _DWORD *v3; 

  result = operator new(0xCu, a1);
  v3 = result;
  if ( result )
  {
    *result = *(_DWORD *)a2;
    result = *(_DWORD **)(a2 + 4);
    v3[1] = result;
    v3[2] = *(_DWORD *)(a2 + 8);
  }
  return result;
}
void DoNothing(int a1)
{
  ;
}


int OpenResource_(HMODULE hModule, LPCSTR lpName, LPCSTR lpType, int a4)
{
  HRSRC hResInfo; 
  HGLOBAL hResData; 

  memset((void *)a4, 0, 0x14u);
  if ( lpType )
  {
    hResInfo = FindResourceA(hModule, lpName, lpType);
    if ( !hResInfo )
      return 0;
    *(_DWORD *)(a4 + 16) = SizeofResource(hModule, hResInfo);
    if ( !*(_DWORD *)(a4 + 16) )
      return 0;
    hResData = LoadResource(hModule, hResInfo);
    if ( !hResData )
      return 0;
    *(_DWORD *)(a4 + 8) = LockResource(hResData);
    if ( !*(_DWORD *)(a4 + 8) )
      return 0;
    *(_DWORD *)a4 = 0;
  }
  else
  {
    *(_DWORD *)(a4 + 4) = fopen(lpName, "rb");
    if ( !*(_DWORD *)(a4 + 4) )
      return 0;
    *(_DWORD *)a4 = 1;
  }
  return 1;
}
int PixelRead(int p, size_t size, int num, int _b_file)
{
  int i; 

  if ( *(_DWORD *)_b_file )
  {
    if ( ReadFromFile((void *)p, size, num, *(FILE **)(_b_file + 4)) != num )
      return 0;
  }
  else
  {
    for ( i = 0; i < num; ++i )
    {
      if ( (signed int)(size + *(_DWORD *)(_b_file + 12)) > *(_DWORD *)(_b_file + 16) )
        return 0;
      memcpy((void *)(i + p), (const void *)(*(_DWORD *)(_b_file + 12) + *(_DWORD *)(_b_file + 8)), size);
      *(_DWORD *)(_b_file + 12) += size;
    }
  }
  return 1;
}
signed int sub_4220D0(int a1, __int32 a2, int a3)
{
  if ( *(_DWORD *)a1 )
  {
    if ( fseek(*(FILE **)(a1 + 4), a2, a3) )
      return 0;
  }
  else if ( a3 )
  {
    if ( a3 == 1 )
    {
      if ( a2 + *(_DWORD *)(a1 + 12) >= *(_DWORD *)(a1 + 16) )
        return 0;
      *(_DWORD *)(a1 + 12) += a2;
    }
    else if ( a3 == 2 )
    {
      return 0;
    }
  }
  else
  {
    if ( a2 >= *(_DWORD *)(a1 + 16) )
      return 0;
    *(_DWORD *)(a1 + 12) = a2;
  }
  return 1;
}
int CloseResource_(int a1)
{
  int result; 

  result = a1;
  if ( *(_DWORD *)a1 )
  {
    if ( *(_DWORD *)(a1 + 4) )
    {
      result = fclose(*(FILE **)(a1 + 4));
      *(_DWORD *)(a1 + 4) = 0;
    }
  }
  else if ( *(_DWORD *)(a1 + 8) )
  {
    result = a1;
    *(_DWORD *)(a1 + 8) = 0;
  }
  return result;
}
signed int VariableLengthCheck(unsigned int a1)
{
  signed int result; 

  if ( a1 >= 0x80 )
  {
    if ( a1 >= 0x4000 )
    {
      if ( a1 >= 0x200000 )
      {
        if ( a1 >= 0x10000000 )
        {
          if ( a1 > 0xFFFFFFFF )
            result = 6;
          else
            result = 5;
        }
        else
        {
          result = 4;
        }
      }
      else
      {
        result = 3;
      }
    }
    else
    {
      result = 2;
    }
  }
  else
  {
    result = 1;
  }
  return result;
}
signed int VariableLengthWrite(unsigned int val, FILE *a2, _DWORD *a3)
{
  unsigned int v3; 
  signed int result; 
  char v5; 
  char v6; 
  char v7; 
  char v8; 
  char v9; 
  unsigned __int8 v10; 
  __int16 v11; 
  unsigned __int8 v12; 
  char v13; 

  v3 = val;
  v10 = val;
  v11 = *(_WORD *)((char *)&v3 + 1);
  v12 = BYTE3(val);
  v13 = 0;
  if ( val >= 0x80 )
  {
    if ( val >= 0x4000 )
    {
      if ( val >= 0x200000 )
      {
        if ( val >= 0x10000000 )
        {
          if ( val > 0xFFFFFFFF )
          {
            result = 0;
          }
          else
          {
            v5 = v10 & 0x7F | 0x80;
            v6 = 2 * v11 & 0x7F | ((signed int)v10 >> 7) | 0x80;
            v7 = 4 * HIBYTE(v11) & 0x7F | ((signed int)(unsigned __int8)v11 >> 6) | 0x80;
            v8 = 8 * v12 & 0x7F | ((signed int)HIBYTE(v11) >> 5) | 0x80;
            v9 = 16 * v13 & 0x7F | ((signed int)v12 >> 4);
            if ( WriteToFile(&v5, 1u, 5u, a2) == 5 )
            {
              if ( a3 )
                *a3 += 5;
              result = 1;
            }
            else
            {
              result = 0;
            }
          }
        }
        else
        {
          v5 = v10 & 0x7F | 0x80;
          v6 = 2 * v11 & 0x7F | ((signed int)v10 >> 7) | 0x80;
          v7 = 4 * HIBYTE(v11) & 0x7F | ((signed int)(unsigned __int8)v11 >> 6) | 0x80;
          v8 = 8 * v12 & 0x7F | ((signed int)HIBYTE(v11) >> 5);
          if ( WriteToFile(&v5, 1u, 4u, a2) == 4 )
          {
            if ( a3 )
              *a3 += 4;
            result = 1;
          }
          else
          {
            result = 0;
          }
        }
      }
      else
      {
        v5 = v10 & 0x7F | 0x80;
        v6 = 2 * v11 & 0x7F | ((signed int)v10 >> 7) | 0x80;
        v7 = 4 * HIBYTE(v11) & 0x7F | ((signed int)(unsigned __int8)v11 >> 6);
        if ( WriteToFile(&v5, 1u, 3u, a2) == 3 )
        {
          if ( a3 )
            *a3 += 3;
          result = 1;
        }
        else
        {
          result = 0;
        }
      }
    }
    else
    {
      v5 = v10 & 0x7F | 0x80;
      v6 = 2 * v11 & 0x7F | ((signed int)v10 >> 7);
      if ( WriteToFile(&v5, 1u, 2u, a2) == 2 )
      {
        if ( a3 )
          *a3 += 2;
        result = 1;
      }
      else
      {
        result = 0;
      }
    }
  }
  else if ( WriteToFile(&v10, 1u, 1u, a2) == 1 )
  {
    if ( a3 )
      ++*a3;
    result = 1;
  }
  else
  {
    result = 0;
  }
  return result;
}

signed int VariableLengthRead(_DWORD *p, int a2)
{
  signed int result; 
  int b; 
  signed int i; 
  int a; 
  char v6; 

  b = 0;
  for ( i = 0; i < 5; ++i )
  {
    if ( !PixelRead((int)&a + i, 1u, 1, a2) )
      return 0;
    if ( !(*((_BYTE *)&a + i) & 0x80) )
      break;
  }
  switch ( i )
  {
    case 0:
      LOBYTE(b) = a & 0x7F;
      goto LABEL_14;
    case 1:
      LOBYTE(b) = (BYTE1(a) << 7) | a & 0x7F;
      BYTE1(b) = (BYTE1(a) & 0x7F) >> 1;
      goto LABEL_14;
    case 2:
      LOBYTE(b) = (BYTE1(a) << 7) | a & 0x7F;
      BYTE1(b) = (BYTE2(a) << 6) | ((BYTE1(a) & 0x7F) >> 1);
      BYTE2(b) = (BYTE2(a) & 0x7F) >> 2;
      goto LABEL_14;
    case 3:
      LOBYTE(b) = (BYTE1(a) << 7) | a & 0x7F;
      BYTE1(b) = (BYTE2(a) << 6) | ((BYTE1(a) & 0x7F) >> 1);
      BYTE2(b) = 32 * BYTE3(a) | ((BYTE2(a) & 0x7F) >> 2);
      BYTE3(b) = (BYTE3(a) & 0x7F) >> 3;
      goto LABEL_14;
    case 4:
      LOBYTE(b) = (BYTE1(a) << 7) | a & 0x7F;
      BYTE1(b) = (BYTE2(a) << 6) | ((BYTE1(a) & 0x7F) >> 1);
      BYTE2(b) = 32 * BYTE3(a) | ((BYTE2(a) & 0x7F) >> 2);
      BYTE3(b) = 16 * v6 | ((BYTE3(a) & 0x7F) >> 3);
      goto LABEL_14;
    case 5:
      result = 0;
      break;
    default:
LABEL_14:
      *p = b;
      result = 1;
      break;
  }
  return result;
}

void **ReleaseEntities(_DWORD *a1)
{
  void **result; 

  result = ReleaseEntityPtr((void **)a1 + 1);
  *a1 = 0;
  return result;
}
void **ReleaseEntityPtr(void **a1)
{
  void **result; 

  result = a1;
  if ( *a1 )
  {
    free(*a1);
    result = a1;
    *a1 = 0;
  }
  return result;
}
signed int Unused4(_DWORD *a1, int a2)
{
  signed int v3; 

  v3 = 0;
  *a1 = a2;
  if ( AllocEntity((int)(a1 + 1), 24 * *a1) )
    v3 = 1;
  if ( !v3 )
    ReleaseEntities(a1);
  return v3;
}
int AllocEntity(int a1, size_t a2)
{
  int result; 

  *(_DWORD *)a1 = malloc(a2);
  if ( *(_DWORD *)a1 )
  {
    memset(*(void **)a1, 0, a2);
    result = 1;
  }
  else
  {
    result = 0;
  }
  return result;
}
signed int ReadPxeve(int ptr, int res?)
{
  int i; 
  signed int v4; 
  int v5; 

  v4 = 0;
  ReleaseEntities((_DWORD *)ptr);
  if ( VariableLengthRead(&v5, res?) )
  {
    *(_DWORD *)ptr = v5;
    if ( AllocEntity(ptr + 4, 24 * *(_DWORD *)ptr) )
    {
      for ( i = 0; i < *(_DWORD *)ptr; ++i )
      {
        if ( !VariableLengthRead(&v5, res?) )
          goto LABEL_12;
        *(_DWORD *)(*(_DWORD *)(ptr + 4) + 24 * i + 8) = v5;
        if ( !VariableLengthRead(&v5, res?) )
          goto LABEL_12;
        *(_DWORD *)(24 * i + *(_DWORD *)(ptr + 4)) = v5;
        if ( !VariableLengthRead(&v5, res?) )
          goto LABEL_12;
        *(_DWORD *)(*(_DWORD *)(ptr + 4) + 24 * i + 4) = v5;
        if ( !VariableLengthRead(&v5, res?) )
          goto LABEL_12;
        *(_DWORD *)(*(_DWORD *)(ptr + 4) + 24 * i + 12) = v5;
        if ( !VariableLengthRead(&v5, res?) )
          goto LABEL_12;
        *(_DWORD *)(*(_DWORD *)(ptr + 4) + 24 * i + 16) = v5;
        *(_DWORD *)(*(_DWORD *)(ptr + 4) + 24 * i + 20) = i;
      }
      v4 = 1;
    }
  }
LABEL_12:
  if ( !v4 )
    ReleaseEntities((_DWORD *)ptr);
  return v4;
}
signed int Unused5(int a1, FILE *a2)
{
  int i; 
  signed int v4; 

  v4 = 0;
  if ( VariableLengthWrite(*(_DWORD *)a1, a2, 0) )
  {
    for ( i = 0; i < *(_DWORD *)a1; ++i )
    {
      if ( !VariableLengthWrite(*(_DWORD *)(*(_DWORD *)(a1 + 4) + 24 * i + 8), a2, 0)
        || !VariableLengthWrite(*(_DWORD *)(*(_DWORD *)(a1 + 4) + 24 * i), a2, 0)
        || !VariableLengthWrite(*(_DWORD *)(*(_DWORD *)(a1 + 4) + 24 * i + 4), a2, 0)
        || !VariableLengthWrite(*(_DWORD *)(*(_DWORD *)(a1 + 4) + 24 * i + 12), a2, 0)
        || !VariableLengthWrite(*(_DWORD *)(*(_DWORD *)(a1 + 4) + 24 * i + 16), a2, 0) )
      {
        return v4;
      }
    }
    v4 = 1;
  }
  return v4;
}
void *ResetInput()
{
  void *result; 

  memset(keyHeld, 0, 0x100u);
  memset(keyHeld2, 0, 0x100u);
  result = memset(gKeyTrg, 0, 0x100u);
  input_0 = 0;
  input_4 = 0;
  input_8 = 0;
  input_c = 0;
  input_10 = 0;
  input_14 = 0;
  return result;
}


HWND KeyCapture_(HWND hWnd, int a2, int a3)
{
  HWND result; 

  result = (HWND)a2;
  if ( (unsigned int)a2 > 0x202 )
  {
    if ( a2 == 516 )
    {
      input_0 |= 0x10u;
      if ( !input_18 )
      {
        input_18 = 1;
        result = SetCapture(hWnd);
      }
    }
    else if ( a2 == 517 )
    {
      result = (HWND)(input_0 & 0xFFFFFFEF);
      input_0 &= 0xFFFFFFEF;
      if ( !(input_0 & 1) )
      {
        input_18 = 0;
        result = (HWND)ReleaseCapture();
      }
    }
  }
  else
  {
    switch ( a2 )
    {
      case 514:
        input_0 &= 0xFFFFFFFE;
        if ( !(input_0 & 0x10) )
        {
          input_18 = 0;
          result = (HWND)ReleaseCapture();
        }
        break;
      case 256:
        keyHeld[a3] = 1;
        break;
      case 257:
        keyHeld[a3] = 0;
        break;
      case 513:
        result = (HWND)(input_0 | 1);
        input_0 |= 1u;
        if ( !input_18 )
        {
          input_18 = 1;
          result = SetCapture(hWnd);
        }
        break;
    }
  }
  return result;
}


int KeyTrigUpdate_()
{
  int result; 
  signed int i; 

  for ( i = 0; i < 256; ++i )
  {
    gKeyTrg[i] = !keyHeld2[i] && keyHeld[i];
    keyHeld2[i] = keyHeld[i];
  }
  input_8 = (input_4 ^ input_0) & input_0;
  input_4 = input_0;
  if ( input_c >= input_10 )
    input_14 = input_c > input_10;
  else
    input_14 = -1;
  result = input_c;
  input_10 = input_c;
  return result;
}


BOOL GetKeyHeld_(int a1)
{
  return keyHeld[a1] != 0;
}
BOOL GetKeyCode(int a1)
{
  return gKeyTrg[a1] != 0;
}
BOOL Unused6()
{
  return (input_0 & 1) != 0;
}

BOOL Unused7()
{
  return (input_0 & 0x10) != 0;
}

BOOL Unused8()
{
  return (input_8 & 1) != 0;
}

BOOL Unused9()
{
  return (input_8 & 0x10) != 0;
}

BOOL SetFullscreenWindowPos(HWND hWnd)
{
  WINDOWPLACEMENT wndpl; 
  struct tagRECT Rect; 
  HWND v4; 
  struct tagRECT v5; 
  int X; 
  int Y; 
  int pvParam; 
  int v9; 
  LONG v10; 
  LONG v11; 

  SystemParametersInfoA(0x30u, 0, &pvParam, 0);
  GetWindowRect(hWnd, &Rect);
  v4 = GetParent(hWnd);
  if ( v4 )
  {
    wndpl.length = 44;
    GetWindowPlacement(v4, &wndpl);
    if ( wndpl.showCmd && wndpl.showCmd != 2 )
      GetWindowRect(v4, &v5);
    else
      SystemParametersInfoA(0x30u, 0, &v5, 0);
  }
  else
  {
    SystemParametersInfoA(0x30u, 0, &v5, 0);
  }
  X = v5.left + (v5.right - v5.left - (Rect.right - Rect.left)) / 2;
  Y = v5.top + (v5.bottom - v5.top - (Rect.bottom - Rect.top)) / 2;
  if ( v5.left + (v5.right - v5.left - (Rect.right - Rect.left)) / 2 < pvParam )
    X = pvParam;
  if ( Y < v9 )
    Y = v9;
  if ( X + Rect.right - Rect.left > v10 )
    X = v10 - (Rect.right - Rect.left);
  if ( Y + Rect.bottom - Rect.top > v11 )
    Y = v11 - (Rect.bottom - Rect.top);
  return SetWindowPos(hWnd, 0, X, Y, 0, 0, 0x41u);
}
int SetPtrTempGuxt(int a1)
{
  int result; 

  result = a1;
  *(_DWORD *)PtrToTempGuxt = a1;
  return result;
}
int SetWindowPosRect(HWND hWnd, int a2, int a3)
{
  int result; 
  char v4; 
  int v5; 
  int v6; 
  int v7; 
  FILE *v8; 
  int v9; 
  int X; 
  int Y; 
  int v12; 
  int v13; 
  int v14; 
  int pvParam; 
  int v16; 
  int v17; 
  int v18; 

  v14 = 1;
  sprintf_((int)&v4, "%s\\%s", *(_DWORD *)PtrToTempGuxt, a2);
  v8 = fopen(&v4, "rb");
  if ( v8 )
  {
    ReadFromFile(&X, 0x10u, 1u, v8);
    ReadFromFile(&v14, 4u, 1u, v8);
    fclose(v8);
    SystemParametersInfoA(0x30u, 0, &pvParam, 0);
    v7 = GetSystemMetrics(61);
    v5 = GetSystemMetrics(62);
    v6 = GetSystemMetrics(28);
    v9 = GetSystemMetrics(29);
    if ( v12 - X < v6 )
      v12 = v6 + X;
    if ( v13 - Y < v9 )
      v13 = v9 + Y;
    if ( v12 - X > v7 )
      v12 = v7 + X;
    if ( v13 - Y > v5 )
      v13 = v5 + Y;
    if ( X < pvParam )
    {
      v12 += pvParam - X;
      X = pvParam;
    }
    if ( Y < v16 )
    {
      v13 += v16 - Y;
      Y = v16;
    }
    if ( v12 > v17 )
    {
      X -= v12 - v17;
      v12 -= v12 - v17;
    }
    if ( v13 > v18 )
    {
      Y -= v13 - v18;
      v13 -= v13 - v18;
    }
    if ( a3 )
      MoveWindow(hWnd, X, Y, v12 - X, v13 - Y, 0);
    else
      SetWindowPos(hWnd, 0, X, Y, 0, 0, 1u);
    if ( v14 == 3 )
      ShowWindow(hWnd, 3);
    else
      ShowWindow(hWnd, 1);
    result = 1;
  }
  else
  {
    result = 0;
  }
  return result;
}
int SaveWindowRect(HWND hWnd, int a2)
{
  int result; 
  char v3; 
  WINDOWPLACEMENT wndpl; 
  FILE *v5; 
  struct tagRECT Rect; 

  if ( !GetWindowPlacement(hWnd, &wndpl) )
    return 0;
  if ( wndpl.showCmd == 1 )
  {
    if ( !GetWindowRect(hWnd, &Rect) )
      return 0;
    wndpl.rcNormalPosition = Rect;
  }
  sprintf_((int)&v3, "%s\\%s", *(_DWORD *)PtrToTempGuxt, a2);
  v5 = fopen(&v3, "wb");
  if ( v5 )
  {
    WriteToFile(&wndpl.rcNormalPosition, 0x10u, 1u, v5);
    WriteToFile(&wndpl.showCmd, 4u, 1u, v5);
    fclose(v5);
    result = 1;
  }
  else
  {
    result = 0;
  }
  return result;
}
BOOL CloseMutex(int this)
{
  BOOL result; 
  int v2; 

  v2 = this;
  if ( *(_DWORD *)(this + 4) )
    ReleaseMutex(*(HANDLE *)(this + 4));
  if ( *(_DWORD *)v2 )
    CloseHandle(*(HANDLE *)v2);
  result = v2;
  if ( *(_DWORD *)(v2 + 8) )
    result = UnmapViewOfFile(*(LPCVOID *)(v2 + 8));
  return result;
}
int StartMutex(int this, LPCSTR lpName, LPCSTR a3)
{
  int result; 
  int v4; 

  v4 = this;
  *(_DWORD *)(this + 4) = OpenMutexA(0x1F0001u, 0, lpName);
  if ( *(_DWORD *)(v4 + 4) )
  {
    ShowExistingWindow(a3);
    result = 0;
  }
  else
  {
    *(_DWORD *)(v4 + 4) = CreateMutexA(0, 0, lpName);
    result = *(_DWORD *)(v4 + 4) != 0;
  }
  return result;
}
HANDLE ShowExistingWindow(LPCSTR lpName)
{
  HANDLE result; 
  HANDLE hObject; 
  HWND *lpBaseAddress; 

  result = CreateFileMappingA((HANDLE)0xFFFFFFFF, 0, 4u, 0, 4u, lpName);
  hObject = result;
  if ( result )
  {
    if ( GetLastError() == 183 )
    {
      lpBaseAddress = (HWND *)MapViewOfFile(hObject, 2u, 0, 0, 4u);
      if ( lpBaseAddress )
      {
        if ( IsWindowVisible(*lpBaseAddress) )
        {
          SetForegroundWindow(*lpBaseAddress);
          ShowWindow(*lpBaseAddress, 1);
        }
        UnmapViewOfFile(lpBaseAddress);
        result = (HANDLE)CloseHandle(hObject);
      }
      else
      {
        result = (HANDLE)CloseHandle(hObject);
      }
    }
    else
    {
      result = (HANDLE)CloseHandle(hObject);
    }
  }
  return result;
}
int StartMutex2(int this, LPCSTR lpName, LPCSTR a3, int a4)
{
  int result; 
  int v5; 

  v5 = this;
  *(_DWORD *)(this + 4) = CreateMutexA(0, 0, lpName);
  if ( *(_DWORD *)(v5 + 4) )
  {
    *(_DWORD *)v5 = CreateFileMappingA((HANDLE)0xFFFFFFFF, 0, 4u, 0, 4u, a3);
    if ( *(_DWORD *)v5 )
    {
      *(_DWORD *)(v5 + 8) = MapViewOfFile(*(HANDLE *)v5, 2u, 0, 0, 4u);
      if ( *(_DWORD *)(v5 + 8) )
      {
        **(_DWORD **)(v5 + 8) = a4;
        result = 1;
      }
      else
      {
        ReleaseMutex(*(HANDLE *)(v5 + 4));
        *(_DWORD *)(v5 + 4) = 0;
        CloseHandle(*(HANDLE *)v5);
        *(_DWORD *)v5 = 0;
        result = 0;
      }
    }
    else
    {
      ReleaseMutex(*(HANDLE *)(v5 + 4));
      *(_DWORD *)(v5 + 4) = 0;
      result = 0;
    }
  }
  else
  {
    result = 0;
  }
  return result;
}
int sprintf_(int arg0, char *arg4, ...)
{
  int result; 
  char v3; 
  char v4[267]; 
  va_list v5; 
  int v6; 
  int v7; 
  int v8; 
  va_list va; 

  va_start(va, arg4);
  v8 = 0;
  v6 = 0;
  v5 = va;
  vsprintf(&v3, arg4, va);
  v5 = 0;
  v7 = strlen(&v3);
  if ( v7 < 260 )
  {
    while ( v8 < v7 + 1 )
    {
      *(_BYTE *)(v6 + arg0) = *(&v3 + v8);
      if ( *(&v3 + v8) != 92 || v4[v8] != 92 )
      {
        if ( *(&v3 + v8) == 47 && v4[v8] == 47 )
          ++v8;
      }
      else
      {
        ++v8;
      }
      ++v8;
      ++v6;
    }
    result = 1;
  }
  else
  {
    result = 0;
  }
  return result;
}

BOOL sub_426400(HWND a1, CHAR *a2, const CHAR *a3, const CHAR *a4, const CHAR *a5, const CHAR *a6)
{
  struct tagOFNA v7; 

  memset(&v7, 0, 0x4Cu);
  v7.lStructSize = 76;
  v7.hwndOwner = a1;
  v7.lpstrFilter = a6;
  v7.lpstrFile = a2;
  v7.nMaxFile = 260;
  v7.lpstrFileTitle = 0;
  v7.nMaxFileTitle = 0;
  v7.lpstrInitialDir = a3;
  v7.lpstrTitle = a4;
  v7.Flags = 6148;
  v7.lpstrDefExt = a5;
  return GetOpenFileNameA(&v7) != 0;
}
BOOL Unused12(HWND a1, CHAR *a2, const CHAR *a3, const CHAR *a4, const CHAR *a5)
{
  struct tagOFNA v6; 

  memset(&v6, 0, 0x4Cu);
  v6.lStructSize = 76;
  v6.hwndOwner = a1;
  v6.lpstrFilter = a5;
  v6.lpstrFile = a2;
  v6.nMaxFile = 260;
  v6.lpstrFileTitle = 0;
  v6.nMaxFileTitle = 0;
  v6.lpstrInitialDir = 0;
  v6.lpstrTitle = a3;
  v6.Flags = 6;
  v6.lpstrDefExt = a4;
  return GetSaveFileNameA(&v6) != 0;
}
int SetUnusedPtrTempGuxt(int a1)
{
  int result; 

  result = a1;
  *(_DWORD *)UnusedPtrTempGuxt = a1;
  return result;
}
int Unused13(LPCSTR pszPath, int a2)
{
  char v3[4]; 
  int v4; 
  FILE *v5; 

  v4 = 0;
  v5 = 0;
  if ( sprintf_((int)v3, "%s\\%s", *(_DWORD *)UnusedPtrTempGuxt, a2) )
  {
    v5 = fopen(v3, "rb");
    if ( v5 )
    {
      if ( ReadFromFile((void *)pszPath, 1u, 0x104u, v5) == 260 && PathIsDirectoryA(pszPath) )
        v4 = 1;
    }
  }
  if ( v5 )
    fclose(v5);
  return v4;
}
int Unused14(char *a1, int a2)
{
  CHAR pszPath[4]; 
  int v4; 
  FILE *v5; 

  v4 = 0;
  v5 = 0;
  sprintf_((int)pszPath, "%s\\%s", *(_DWORD *)UnusedPtrTempGuxt, a2);
  v5 = fopen(pszPath, "wb");
  if ( v5 )
  {
    strcpy(pszPath, a1);
    PathRemoveFileSpecA(pszPath);
    if ( WriteToFile(pszPath, 1u, 0x104u, v5) == 260 )
      v4 = 1;
  }
  if ( v5 )
    fclose(v5);
  return v4;
}
int Unused15(int a1)
{
  int result; 
  int i; 

  for ( i = 0; ; ++i )
  {
    result = i + a1;
    if ( !*(_BYTE *)(i + a1) )
      break;
    if ( *(_BYTE *)(i + a1) == 92
      || *(_BYTE *)(i + a1) == 47
      || *(_BYTE *)(i + a1) == 58
      || *(_BYTE *)(i + a1) == 44
      || *(_BYTE *)(i + a1) == 59
      || *(_BYTE *)(i + a1) == 42
      || *(_BYTE *)(i + a1) == 63
      || *(_BYTE *)(i + a1) == 34
      || *(_BYTE *)(i + a1) == 60
      || *(_BYTE *)(i + a1) == 62
      || *(_BYTE *)(i + a1) == 124 )
    {
      *(_BYTE *)(i + a1) = 120;
    }
  }
  return result;
}
HRESULT Unused16(CHAR *pszPath)
{
  HRESULT result; 
  HWND v2; 
  IMalloc *ppMalloc; 
  LPITEMIDLIST ppidl; 

  result = SHGetMalloc(&ppMalloc);
  if ( result >= 0 )
  {
    v2 = GetDesktopWindow();
    SHGetSpecialFolderLocation(v2, 0, &ppidl);
    SHGetPathFromIDListA(ppidl, pszPath);
    ppMalloc->lpVtbl->Free(ppMalloc, ppidl);
    result = ppMalloc->lpVtbl->Release(ppMalloc);
  }
  return result;
}
int memset12bytes(void *a1)
{
  memset(a1, 0, 12u);
  return 1;
}
void *Unused10(int a1)
{
  return memset(*(void **)(a1 + 8), 0, *(_DWORD *)(a1 + 4) * *(_DWORD *)a1);
}
signed int Unused11(int a1, signed int a2, signed int a3, char a4)
{
  signed int result; 
  int v5; 
  int v6; 
  int v7; 
  int v8; 
  signed int v9; 
  signed int v10; 
  int v11; 

  if ( a2 > 0x7FFF )
    a2 = 0x7FFF;
  if ( a3 > 0x7FFF )
    a3 = 0x7FFF;
  if ( a2 < 1 )
    a2 = 1;
  if ( a3 < 1 )
    a3 = 1;
  v7 = 0;
  v8 = 0;
  if ( a4 & 1 )
    v7 = a2 - *(_DWORD *)a1;
  if ( a4 & 2 )
    v8 = a3 - *(_DWORD *)(a1 + 4);
  if ( sub_4269B0((int)&v11, a3 * a2) )
  {
    if ( *(_DWORD *)(a1 + 8) )
    {
      v6 = 0;
      v10 = v8;
      while ( v6 < *(_DWORD *)(a1 + 4) )
      {
        v5 = 0;
        v9 = v7;
        while ( v5 < *(_DWORD *)a1 )
        {
          if ( v9 >= 0 && v9 < a2 && v10 >= 0 && v10 < a3 )
            *(_BYTE *)(v11 + v9 + a2 * v10) = *(_BYTE *)(v5 + *(_DWORD *)a1 * v6 + *(_DWORD *)(a1 + 8));
          ++v5;
          ++v9;
        }
        ++v6;
        ++v10;
      }
      FreeStageAttr((void **)(a1 + 8));
    }
    *(_DWORD *)(a1 + 8) = v11;
    *(_DWORD *)a1 = (unsigned __int16)a2;
    *(_DWORD *)(a1 + 4) = (unsigned __int16)a3;
    result = 1;
  }
  else
  {
    result = 0;
  }
  return result;
}
int sub_4269B0(int a1, size_t a2)
{
  int result; 

  *(_DWORD *)a1 = malloc(a2);
  if ( *(_DWORD *)a1 )
  {
    memset(*(void **)a1, 0, a2);
    result = 1;
  }
  else
  {
    result = 0;
  }
  return result;
}
void **FreeStageAttr(void **a1)
{
  void **result; 

  result = a1;
  if ( *a1 )
  {
    free(*a1);
    result = a1;
    *a1 = 0;
  }
  return result;
}
void **ReleaseStageAttr(int a1)
{
  void **result; 

  result = FreeStageAttr((void **)(a1 + 8));
  *(_DWORD *)a1 = 0;
  *(_DWORD *)(a1 + 4) = 0;
  return result;
}
int LoadStageAttr(int a1, int a2)
{
  int v3; 
  size_t v4; 
  int v5; 

  v5 = 0;
  ReleaseStageAttr(a1);
  if ( PixelRead((int)&v3, 2u, 1, a2) )
  {
    *(_DWORD *)a1 = (unsigned __int16)v3;
    if ( PixelRead((int)&v3, 2u, 1, a2) )
    {
      *(_DWORD *)(a1 + 4) = (unsigned __int16)v3;
      v4 = *(_DWORD *)(a1 + 4) * *(_DWORD *)a1;
      *(_DWORD *)(a1 + 8) = malloc(v4);
      if ( *(_DWORD *)(a1 + 8) )
      {
        if ( PixelRead(*(_DWORD *)(a1 + 8), 1u, v4, a2) )
          v5 = 1;
      }
    }
  }
  if ( !v5 )
    ReleaseStageAttr(a1);
  return v5;
}
int pxtnPulse_Noise::Fix(int a1)
{
  int result; 
  int j; 
  int i; 
  int v4; 

  if ( *(_DWORD *)a1 > 441000 )
    *(_DWORD *)a1 = 441000;
  for ( i = 0; ; ++i )
  {
    result = a1;
    if ( i >= *(_DWORD *)(a1 + 4) )
      break;
    v4 = *(_DWORD *)(a1 + 8) + 76 * i;
    if ( *(_DWORD *)v4 )
    {
      for ( j = 0; j < *(_DWORD *)(v4 + 4); ++j )
      {
        if ( *(_DWORD *)(*(_DWORD *)(v4 + 8) + 8 * j) > 10000 )
          *(_DWORD *)(*(_DWORD *)(v4 + 8) + 8 * j) = 10000;
        if ( *(_DWORD *)(*(_DWORD *)(v4 + 8) + 8 * j) < 0 )
          *(_DWORD *)(*(_DWORD *)(v4 + 8) + 8 * j) = 0;
        if ( *(_DWORD *)(*(_DWORD *)(v4 + 8) + 8 * j + 4) > 100 )
          *(_DWORD *)(*(_DWORD *)(v4 + 8) + 8 * j + 4) = 100;
        if ( *(_DWORD *)(*(_DWORD *)(v4 + 8) + 8 * j + 4) < 0 )
          *(_DWORD *)(*(_DWORD *)(v4 + 8) + 8 * j + 4) = 0;
      }
      PxNoise_FixUnit(v4 + 16);
      PxNoise_FixUnit(v4 + 36);
      PxNoise_FixUnit(v4 + 56);
    }
  }
  return result;
}
void PxNoise_FixUnit(int a1)
{
  if ( *(_DWORD *)a1 >= 7 )
    *(_DWORD *)a1 = 0;
  if ( *(float *)(a1 + 4) > 44100.0 )
    *(_DWORD *)(a1 + 4) = 1194083328;
  if ( *(float *)(a1 + 8) > 200.0 )
    *(_DWORD *)(a1 + 8) = 1128792064;
  if ( *(float *)(a1 + 12) > 100.0 )
    *(_DWORD *)(a1 + 12) = 1120403456;
}
int DecodePtnoise_(void **a1, int a2, int a3, signed int a4, int a5)
{
  double v6; 
  double v7; 
  int _unit_num; 
  int i; 
  int k; 
  double v11; 
  int v12; 
  int v13; 
  int v14; 
  int v15; 
  int v16; 
  int v17; 
  int v18; 
  double v19; 
  int v20; 
  int j; 
  int u; 
  double v23; 
  double v24; 
  _WORD *v25; 

  v20 = 0;
  v15 = 0;
  pxtnPulse_Noise::Fix(a2);
  _unit_num = *(_DWORD *)(a2 + 4);
  if ( pxtnPulse_NoiseBuilder::Init() && pxtnMem_zero_alloc((int)&v15, 208 * _unit_num) )
  {
    for ( u = 0; u < _unit_num; ++u )
    {
      v18 = v15 + 208 * u;
      *(_DWORD *)(v15 + 208 * u) = *(_DWORD *)(76 * u + *(_DWORD *)(a2 + 8));
      *(_DWORD *)(v18 + 52) = *(_DWORD *)(*(_DWORD *)(a2 + 8) + 76 * u + 4);
      if ( *(_DWORD *)(*(_DWORD *)(a2 + 8) + 76 * u + 12) )
      {
        if ( *(_DWORD *)(*(_DWORD *)(a2 + 8) + 76 * u + 12) >= 0 )
        {
          *(double *)(v18 + 16) = 1.0;
          *(double *)(v18 + 8) = (100.0 - (double)*(signed int *)(*(_DWORD *)(a2 + 8) + 76 * u + 12)) / 100.0;
        }
        else
        {
          *(double *)(v18 + 8) = 1.0;
          *(double *)(v18 + 16) = ((double)*(signed int *)(*(_DWORD *)(a2 + 8) + 76 * u + 12) + 100.0) / 100.0;
        }
      }
      else
      {
        *(double *)(v18 + 8) = 1.0;
        *(double *)(v18 + 16) = 1.0;
      }
      if ( !pxtnMem_zero_alloc(v18 + 56, 16 * *(_DWORD *)(v18 + 52)) )
        goto LABEL_78;
      for ( i = 0; i < *(_DWORD *)(*(_DWORD *)(a2 + 8) + 76 * u + 4); ++i )
      {
        *(_DWORD *)(16 * i + *(_DWORD *)(v18 + 56)) = *(_DWORD *)(*(_DWORD *)(*(_DWORD *)(a2 + 8) + 76 * u + 8) + 8 * i)
                                                    * a4
                                                    / 1000;
        *(double *)(*(_DWORD *)(v18 + 56) + 16 * i + 8) = (double)*(signed int *)(*(_DWORD *)(*(_DWORD *)(a2 + 8)
                                                                                            + 76 * u
                                                                                            + 8)
                                                                                + 8 * i
                                                                                + 4)
                                                        / 100.0;
      }
      *(_DWORD *)(v18 + 24) = 0;
      *(double *)(v18 + 32) = 0.0;
      *(double *)(v18 + 40) = 0.0;
      *(_DWORD *)(v18 + 48) = 0;
      while ( *(_DWORD *)(v18 + 24) < *(_DWORD *)(v18 + 52) )
      {
        *(double *)(v18 + 40) = *(double *)(*(_DWORD *)(v18 + 56) + 16 * *(_DWORD *)(v18 + 24) + 8)
                              - *(double *)(v18 + 32);
        if ( *(_DWORD *)(16 * *(_DWORD *)(v18 + 24) + *(_DWORD *)(v18 + 56)) )
          break;
        *(double *)(v18 + 32) = *(double *)(*(_DWORD *)(v18 + 56) + 16 * (*(_DWORD *)(v18 + 24))++ + 8);
      }
      sub_427CD0(v18 + 64, *(_DWORD *)(a2 + 8) + 76 * u + 16, a4);
      sub_427CD0(v18 + 112, *(_DWORD *)(a2 + 8) + 76 * u + 36, a4);
      sub_427CD0(v18 + 160, *(_DWORD *)(a2 + 8) + 76 * u + 56, a4);
    }
    v25 = 0;
    v16 = *(_DWORD *)a2 / (44100 / a4);
    if ( *a1 )
    {
      free(*a1);
      *a1 = 0;
    }
    *a1 = malloc(a5 * a3 * v16 / 8);
    if ( !*a1 )
      return 0;
    v25 = *a1;
    for ( j = 0; j < v16; ++j )
    {
      for ( k = 0; k < a3; ++k )
      {
        v11 = 0.0;
        for ( u = 0; u < _unit_num; ++u )
        {
          v18 = v15 + 208 * u;
          if ( *(_DWORD *)(v15 + 208 * u) )
          {
            if ( *(_DWORD *)(v18 + 96) )
            {
              if ( *(double *)(v18 + 72) < 0.0 )
                v19 = 0.0;
              else
                v19 = (double)((signed int)(*(_DWORD *)(v18 + 104) * (unsigned __int64)*(double *)(v18 + 72)) / smp_num
                             + *(_DWORD *)(v18 + 100));
            }
            else
            {
              if ( *(_DWORD *)(v18 + 92) )
                v12 = smp_num - (unsigned __int64)*(double *)(v18 + 72) - 1;
              else
                v12 = (unsigned __int64)*(double *)(v18 + 72);
              if ( v12 < 0 )
                v19 = 0.0;
              else
                v19 = (double)*(_WORD *)(*(_DWORD *)(v18 + 88) + 2 * v12);
            }
            v19 = v19 * *(double *)(v18 + 80);
            if ( *(_DWORD *)(v18 + 192) )
            {
              v23 = (double)((signed int)(*(_DWORD *)(v18 + 200) * (unsigned __int64)*(double *)(v18 + 168)) / smp_num
                           + *(_DWORD *)(v18 + 196));
            }
            else
            {
              if ( *(_DWORD *)(v18 + 188) )
                v13 = smp_num - (unsigned __int64)*(double *)(v18 + 168) - 1;
              else
                v13 = (unsigned __int64)*(double *)(v18 + 168);
              v23 = (double)*(_WORD *)(*(_DWORD *)(v18 + 184) + 2 * v13);
            }
            v23 = v23 * *(double *)(v18 + 176);
            v19 = (v23 + 32767.0) * v19 / 65534.0;
            v19 = v19 * *(double *)(v18 + 8 * k + 8);
            if ( *(_DWORD *)(v18 + 24) >= *(_DWORD *)(v18 + 52) )
              v19 = v19 * *(double *)(v18 + 32);
            else
              v19 = ((double)*(signed int *)(v18 + 48)
                   * *(double *)(v18 + 40)
                   / (double)*(signed int *)(*(_DWORD *)(v18 + 56) + 16 * *(_DWORD *)(v18 + 24))
                   + *(double *)(v18 + 32))
                  * v19;
            v11 = v11 + v19;
          }
        }
        v17 = (unsigned __int64)v11;
        if ( v17 > 0x7FFF )
          v17 = 0x7FFF;
        if ( v17 < -32767 )
          v17 = -32767;
        if ( a5 == 8 )
        {
          *(_BYTE *)v25 = BYTE1(v17) + -128;
          v25 = (_WORD *)((char *)v25 + 1);
        }
        else
        {
          *v25 = v17;
          ++v25;
        }
      }
      for ( u = 0; u < _unit_num; ++u )
      {
        v18 = v15 + 208 * u;
        if ( *(_DWORD *)(v15 + 208 * u) )
        {
          if ( *(_DWORD *)(v18 + 144) )
          {
            v24 = (double)((signed int)(*(_DWORD *)(v18 + 152) * (unsigned __int64)*(double *)(v18 + 120)) / smp_num
                         + *(_DWORD *)(v18 + 148));
          }
          else
          {
            v14 = *(_DWORD *)(v18 + 140) ? smp_num - (unsigned __int64)*(double *)(v18 + 120) - 1 : (unsigned int)(unsigned __int64)*(double *)(v18 + 120);
            v24 = (double)(12800 * *(_WORD *)(*(_DWORD *)(v18 + 136) + 2 * v14) / 0x7FFF);
          }
          v6 = v24 * *(double *)(v18 + 128);
          v24 = v6;
          v7 = sub_428C20((unsigned __int64)v6);
          sub_427DC0(v18 + 64, v7 * *(double *)(v18 + 64));
          sub_427DC0(v18 + 112, *(double *)(v18 + 112));
          sub_427DC0(v18 + 160, *(double *)(v18 + 160));
          if ( *(_DWORD *)(v18 + 24) < *(_DWORD *)(v18 + 52)
            && ++*(_DWORD *)(v18 + 48) >= *(_DWORD *)(16 * *(_DWORD *)(v18 + 24) + *(_DWORD *)(v18 + 56)) )
          {
            *(_DWORD *)(v18 + 48) = 0;
            *(double *)(v18 + 32) = *(double *)(*(_DWORD *)(v18 + 56) + 16 * *(_DWORD *)(v18 + 24) + 8);
            *(double *)(v18 + 40) = 0.0;
            ++*(_DWORD *)(v18 + 24);
            while ( *(_DWORD *)(v18 + 24) < *(_DWORD *)(v18 + 52) )
            {
              *(double *)(v18 + 40) = *(double *)(*(_DWORD *)(v18 + 56) + 16 * *(_DWORD *)(v18 + 24) + 8)
                                    - *(double *)(v18 + 32);
              if ( *(_DWORD *)(16 * *(_DWORD *)(v18 + 24) + *(_DWORD *)(v18 + 56)) )
                break;
              *(double *)(v18 + 32) = *(double *)(*(_DWORD *)(v18 + 56) + 16 * (*(_DWORD *)(v18 + 24))++ + 8);
            }
          }
        }
      }
    }
    v20 = 1;
  }
LABEL_78:
  sub_427630();
  return v20;
}

int pxtnMem_zero_alloc(int pp, size_t byte_size)
{
  int result; 

  *(_DWORD *)pp = malloc(byte_size);
  if ( *(_DWORD *)pp )
  {
    memset(*(void **)pp, 0, byte_size);
    result = 1;
  }
  else
  {
    result = 0;
  }
  return result;
}
int sub_427630()
{
  int result; 
  signed int i; 

  for ( i = 0; i < 7; ++i )
  {
    pxtnMem_free((void **)(4 * i + 4511644));
    result = i + 1;
  }
  return result;
}
void **pxtnMem_free(void **a1)
{
  void **result; 

  result = a1;
  if ( *a1 )
  {
    free(*a1);
    result = a1;
    *a1 = 0;
  }
  return result;
}
int pxtnPulse_NoiseBuilder::Init()
{
  int v1; 
  int v2; 
  int v3; 
  int v4; 
  int v5; 
  int v6; 
  int v7; 
  int v8; 
  int v9; 
  int v10; 
  int v11; 
  int v12; 
  int v13; 
  int v14; 
  int v15; 
  int v16; 
  int v17; 
  int v18; 
  int v19; 
  int v20; 
  int v21; 
  int v22; 
  int v23; 
  int v24; 
  int v25; 
  int v26; 
  int v27; 
  int v28; 
  int v29; 
  int v30; 
  int v31; 
  int v32; 
  int v33; 
  int v34; 
  int v35; 
  int v36; 
  int v37; 
  int v38; 
  int v39; 
  int v40; 
  int v41; 
  int v42; 
  int v43; 
  int v44; 
  int v45; 
  int v46; 
  int v47; 
  int v48; 
  double work; 
  signed int index; 
  int _b_init; 
  pxtnPOINT overtones_sine; 
  __int16 *p; 

  _b_init = 0;
  pxtnPulse_NoiseBuilder::_random_reset();
  for ( index = 0; index < 7; ++index )
    p_tables_NONE[index] = 0;
  if ( pxtnMem_zero_alloc((int)p_tables_NONE, 2 * smp_num) && pxtnMem_zero_alloc((int)&p_tables_SAW, 2 * smp_num) )
  {
    overtones_sine.x = 1;
    overtones_sine.y = 128;
    pxtnPulse_Oscillator::ReadyGetSample((int)&overtones_sine, 1, 128, smp_num, 0);
    p = (__int16 *)p_tables_SAW;
    for ( index = 0; index < smp_num; ++index )
    {
      work = pxtnPulse_Oscillator::GetOneSample_Overtone(index);
      if ( work > 1.0 )
        work = 1.0;
      if ( work < -1.0 )
        work = -1.0;
      *p = (unsigned __int64)(work * 32767.0);
      ++p;
    }
    if ( pxtnMem_zero_alloc((int)&p_tables_RECT, 2 * smp_num) )
    {
      p = (__int16 *)p_tables_RECT;
      work = 65534.0;
      for ( index = 0; index < smp_num; ++index )
      {
        *p = (unsigned __int64)(32767.0 - (double)index * work / (double)smp_num);
        ++p;
      }
      if ( pxtnMem_zero_alloc((int)&p_tables_RANDOM, 2 * smp_num) )
      {
        p = (__int16 *)p_tables_RANDOM;
        for ( index = 0; index < smp_num / 2; ++index )
        {
          *p = 0x7FFF;
          ++p;
        }
        while ( index < smp_num )
        {
          *p = -32767;
          ++p;
          ++index;
        }
        if ( pxtnMem_zero_alloc((int)&p_tables_SAW2, 0x15888u) )
        {
          p = (__int16 *)p_tables_SAW2;
          for ( index = 0; index < 44100; ++index )
          {
            *p = pxtnPulse_NoiseBuilder::_random_get();
            ++p;
          }
          if ( pxtnMem_zero_alloc((int)&p_tables_RECT2, 2 * smp_num) )
          {
            v17 = 1;
            v18 = 128;
            v19 = 2;
            v20 = 128;
            v21 = 3;
            v22 = 128;
            v23 = 4;
            v24 = 128;
            v25 = 5;
            v26 = 128;
            v27 = 6;
            v28 = 128;
            v29 = 7;
            v30 = 128;
            v31 = 8;
            v32 = 128;
            v33 = 9;
            v34 = 128;
            v35 = 10;
            v36 = 128;
            v37 = 11;
            v38 = 128;
            v39 = 12;
            v40 = 128;
            v41 = 13;
            v42 = 128;
            v43 = 14;
            v44 = 128;
            v45 = 15;
            v46 = 128;
            v47 = 16;
            v48 = 128;
            pxtnPulse_Oscillator::ReadyGetSample((int)&v17, 16, 128, smp_num, 0);
            p = (__int16 *)p_tables_RECT2;
            for ( index = 0; index < smp_num; ++index )
            {
              work = pxtnPulse_Oscillator::GetOneSample_Overtone(index);
              if ( work > 1.0 )
                work = 1.0;
              if ( work < -1.0 )
                work = -1.0;
              *p = (unsigned __int64)(work * 32767.0);
              ++p;
            }
            if ( pxtnMem_zero_alloc((int)&p_tables_TRI, 2 * smp_num) )
            {
              v1 = 1;
              v2 = 128;
              v3 = 3;
              v4 = 128;
              v5 = 5;
              v6 = 128;
              v7 = 7;
              v8 = 128;
              v9 = 9;
              v10 = 128;
              v11 = 11;
              v12 = 128;
              v13 = 13;
              v14 = 128;
              v15 = 15;
              v16 = 128;
              pxtnPulse_Oscillator::ReadyGetSample((int)&v1, 8, 128, smp_num, 0);
              p = (__int16 *)p_tables_TRI;
              for ( index = 0; index < smp_num; ++index )
              {
                work = pxtnPulse_Oscillator::GetOneSample_Overtone(index);
                if ( work > 1.0 )
                  work = 1.0;
                if ( work < -1.0 )
                  work = -1.0;
                *p = (unsigned __int64)(work * 32767.0);
                ++p;
              }
              _b_init = 1;
            }
          }
        }
      }
    }
  }
  if ( !_b_init )
    sub_427630();
  return _b_init;
}




void pxtnPulse_NoiseBuilder::_random_reset()
{
  rand_buf = 0x4444;
  rand_buf2 = 0x8888;
}


__int16 pxtnPulse_NoiseBuilder::_random_get()
{
  __int16 w2; 
  int w1; 

  w1 = rand_buf2 + (signed __int16)rand_buf;
  LOBYTE(w2) = BYTE1(w1);
  HIBYTE(w2) = rand_buf2 + rand_buf;
  rand_buf2 = (signed __int16)rand_buf;
  rand_buf = w2;
  return w2;
}


int sub_427CD0(int a1, int a2, signed int a3)
{
  int result; 

  *(_DWORD *)(a1 + 32) = *(_DWORD *)a2 == 4;
  *(double *)a1 = 44100.0 / (double)a3 * (*(float *)(a2 + 4) / 100.0);
  if ( *(_DWORD *)(a1 + 32) )
    *(double *)(a1 + 8) = 0.0;
  else
    *(double *)(a1 + 8) = (double)smp_num * (*(float *)(a2 + 12) / 100.0);
  *(double *)(a1 + 16) = *(float *)(a2 + 8) / 100.0;
  *(_DWORD *)(a1 + 24) = p_tables_NONE[*(_DWORD *)a2];
  *(_DWORD *)(a1 + 28) = *(_DWORD *)(a2 + 16);
  *(_DWORD *)(a1 + 36) = 0;
  *(_DWORD *)(a1 + 44) = (unsigned __int64)(*(float *)(a2 + 12) / 100.0 * 44100.0);
  result = p_tables_SAW2;
  *(_DWORD *)(a1 + 40) = *(_WORD *)(p_tables_SAW2 + 2 * *(_DWORD *)(a1 + 44));
  return result;
}

void sub_427DC0(int a1, double a2)
{
  int v2; 

  *(double *)(a1 + 8) = a2 + *(double *)(a1 + 8);
  if ( (double)smp_num < *(double *)(a1 + 8) )
  {
    *(double *)(a1 + 8) = *(double *)(a1 + 8) - (double)smp_num;
    if ( (double)smp_num <= *(double *)(a1 + 8) )
      *(double *)(a1 + 8) = 0.0;
    if ( *(_DWORD *)(a1 + 32) )
    {
      v2 = p_tables_SAW2;
      *(_DWORD *)(a1 + 36) = *(_WORD *)(p_tables_SAW2 + 2 * (*(_DWORD *)(a1 + 44))++);
      if ( *(_DWORD *)(a1 + 44) >= 44100 )
        *(_DWORD *)(a1 + 44) = 0;
      *(_DWORD *)(a1 + 40) = *(_WORD *)(v2 + 2 * *(_DWORD *)(a1 + 44)) - *(_DWORD *)(a1 + 36);
    }
  }
}


int pxtnPulse_Noise::write(FILE *a1, int *p_add, int a3)
{
  char v4; 
  int j; 
  char v6; 
  int num_seek; 
  int pU; 
  int b_ret; 
  int i; 
  int seek; 
  int flags; 

  b_ret = 0;
  v4 = 0;
  if ( p_add )
    seek = *p_add;
  else
    seek = 0;
  if ( WriteToFile(PtnoiseHeader, 1u, 8u, a1) == 8 && WriteToFile(&PtnoiseVer, 4u, 1u, a1) == 1 )
  {
    seek += 12;
    if ( VariableLengthWrite(*(_DWORD *)a3, a1, &seek) )
    {
      if ( WriteToFile(&v4, 1u, 1u, a1) == 1 )
      {
        num_seek = seek++;
        for ( i = 0; i < *(_DWORD *)(a3 + 4); ++i )
        {
          pU = *(_DWORD *)(a3 + 8) + 76 * i;
          if ( *(_DWORD *)pU )
          {
            flags = MakeFlags(pU);
            if ( !VariableLengthWrite(flags, a1, &seek) )
              return b_ret;
            if ( flags & 4 )
            {
              if ( !VariableLengthWrite(*(_DWORD *)(pU + 4), a1, &seek) )
                return b_ret;
              for ( j = 0; j < *(_DWORD *)(pU + 4); ++j )
              {
                if ( !VariableLengthWrite(*(_DWORD *)(*(_DWORD *)(pU + 8) + 8 * j), a1, &seek)
                  || !VariableLengthWrite(*(_DWORD *)(*(_DWORD *)(pU + 8) + 8 * j + 4), a1, &seek) )
                {
                  return b_ret;
                }
              }
            }
            if ( flags & 8 )
            {
              v6 = *(_BYTE *)(pU + 12);
              if ( (WriteToFile(&v6, 1u, 1u, a1) == 0) != 1 )
                return b_ret;
              ++seek;
            }
            if ( flags & 0x10 && !WriteOscillator((pxNOISEDESIGN_OSCILLATOR *)(pU + 16), a1, &seek)
              || flags & 0x20 && !WriteOscillator((pxNOISEDESIGN_OSCILLATOR *)(pU + 36), a1, &seek)
              || flags & 0x40 && !WriteOscillator((pxNOISEDESIGN_OSCILLATOR *)(pU + 56), a1, &seek) )
            {
              return b_ret;
            }
            ++v4;
          }
        }
        fseek(a1, num_seek - seek, 1);
        if ( WriteToFile(&v4, 1u, 1u, a1) == 1 )
        {
          fseek(a1, seek - num_seek - 1, 1);
          if ( p_add )
            *p_add = seek;
          b_ret = 1;
        }
      }
    }
  }
  return b_ret;
}
int WriteOscillator(pxNOISEDESIGN_OSCILLATOR *p_osc, FILE *a2, _DWORD *p_add)
{
  int result; 

  if ( VariableLengthWrite(p_osc->type, a2, p_add) )
  {
    if ( VariableLengthWrite(*(_DWORD *)&p_osc->b_rev, a2, p_add) )
    {
      if ( VariableLengthWrite((unsigned __int64)(p_osc->freq * 10.0), a2, p_add) )
      {
        if ( VariableLengthWrite((unsigned __int64)(p_osc->volume * 10.0), a2, p_add) )
          result = VariableLengthWrite((unsigned __int64)(p_osc->offset * 10.0), a2, p_add) != 0;
        else
          result = 0;
      }
      else
      {
        result = 0;
      }
    }
    else
    {
      result = 0;
    }
  }
  else
  {
    result = 0;
  }
  return result;
}
signed int MakeFlags(int a1)
{
  signed int v2; 

  v2 = 4;
  if ( *(_DWORD *)(a1 + 12) )
    v2 = 4;
  if ( *(_DWORD *)(a1 + 16) )
    v2 |= 0x10u;
  if ( *(_DWORD *)(a1 + 36) )
    v2 |= 0x20u;
  if ( *(_DWORD *)(a1 + 56) )
    v2 |= 0x40u;
  return v2;
}
int ReadPtnoise_(int a1, void *a2, int a3)
{
  int v4; 
  int v5; 
  int v6; 
  int v7; 
  int v8; 
  int i; 
  int v10; 

  v8 = 0;
  if ( PixelRead((int)&v7, 1u, 8, a1) && !memcmp(&v7, PtnoiseHeader, 8u) && PixelRead((int)&v5 + 1, 4u, 1, a1) )
  {
    if ( *(unsigned int *)((char *)&v5 + 1) <= 20051028 )
    {
      if ( VariableLengthRead(a2, a1) )
      {
        if ( PixelRead((int)&v4, 1u, 1, a1) )
        {
          *((_DWORD *)a2 + 1) = (char)v4;
          if ( *((_DWORD *)a2 + 1) >= 0 )
          {
            if ( *((_DWORD *)a2 + 1) <= 4 )
            {
              if ( pxtnNoise_zero_alloc((int)a2 + 8, 76 * *((_DWORD *)a2 + 1)) )
              {
                for ( i = 0; i < *((_DWORD *)a2 + 1); ++i )
                {
                  v6 = *((_DWORD *)a2 + 2) + 76 * i;
                  *(_DWORD *)v6 = 1;
                  if ( !VariableLengthRead(&v10, a1) )
                    goto LABEL_38;
                  if ( v10 & 0xFFFFFF83 )
                  {
                    *(_DWORD *)a3 = 1;
                    goto LABEL_38;
                  }
                  if ( v10 & 4 )
                  {
                    if ( !VariableLengthRead((_DWORD *)(v6 + 4), a1) )
                      goto LABEL_38;
                    if ( *(_DWORD *)(v6 + 4) > 3 )
                    {
                      *(_DWORD *)a3 = 1;
                      goto LABEL_38;
                    }
                    if ( !pxtnNoise_zero_alloc(v6 + 8, 8 * *(_DWORD *)(v6 + 4)) )
                      goto LABEL_38;
                    for ( *(int *)((char *)&v4 + 1) = 0;
                          *(int *)((char *)&v4 + 1) < *(_DWORD *)(v6 + 4);
                          ++*(int *)((char *)&v4 + 1) )
                    {
                      if ( !VariableLengthRead((_DWORD *)(*(_DWORD *)(v6 + 8) + 8 * *(int *)((char *)&v4 + 1)), a1)
                        || !VariableLengthRead((_DWORD *)(*(_DWORD *)(v6 + 8) + 8 * *(int *)((char *)&v4 + 1) + 4), a1) )
                      {
                        goto LABEL_38;
                      }
                    }
                  }
                  if ( v10 & 8 )
                  {
                    if ( !PixelRead((int)&v5, 1u, 1, a1) )
                      goto LABEL_38;
                    *(_DWORD *)(v6 + 12) = (char)v5;
                  }
                  if ( v10 & 0x10 && !ReadPtnoise2_(v6 + 16, a1)
                    || v10 & 0x20 && !ReadPtnoise2_(v6 + 36, a1)
                    || v10 & 0x40 && !ReadPtnoise2_(v6 + 56, a1) )
                  {
                    goto LABEL_38;
                  }
                }
                v8 = 1;
              }
            }
            else
            {
              *(_DWORD *)a3 = 1;
            }
          }
        }
      }
    }
    else
    {
      *(_DWORD *)a3 = 1;
    }
  }
LABEL_38:
  if ( !v8 )
    pxtnPulse_Noise::Release(a2);
  return v8;
}
int pxtnNoise_zero_alloc(int a1, size_t a2)
{
  int result; 

  *(_DWORD *)a1 = malloc(a2);
  if ( *(_DWORD *)a1 )
  {
    memset(*(void **)a1, 0, a2);
    result = 1;
  }
  else
  {
    result = 0;
  }
  return result;
}
signed int ReadPtnoise2_(int a1, int a2)
{
  int v2; 
  signed int result; 
  int v4; 

  v4 = v2;
  if ( VariableLengthRead(&v4, a2) )
  {
    *(_DWORD *)a1 = v4;
    if ( VariableLengthRead(&v4, a2) )
    {
      *(_DWORD *)(a1 + 16) = v4;
      if ( VariableLengthRead(&v4, a2) )
      {
        *(float *)(a1 + 4) = (double)v4 / 10.0;
        if ( VariableLengthRead(&v4, a2) )
        {
          *(float *)(a1 + 8) = (double)v4 / 10.0;
          if ( VariableLengthRead(&v4, a2) )
          {
            *(float *)(a1 + 12) = (double)v4 / 10.0;
            result = 1;
          }
          else
          {
            result = 0;
          }
        }
        else
        {
          result = 0;
        }
      }
      else
      {
        result = 0;
      }
    }
    else
    {
      result = 0;
    }
  }
  else
  {
    result = 0;
  }
  return result;
}
void *pxtnPulse_Noise::Release(void *a1)
{
  int i; 

  if ( *((_DWORD *)a1 + 2) )
  {
    for ( i = 0; i < *((_DWORD *)a1 + 1); ++i )
    {
      if ( *(_DWORD *)(*((_DWORD *)a1 + 2) + 76 * i + 8) )
        pxtnNoise_free((void **)(*((_DWORD *)a1 + 2) + 76 * i + 8));
    }
    pxtnNoise_free((void **)a1 + 2);
  }
  return memset(a1, 0, 0xCu);
}
void **pxtnNoise_free(void **a1)
{
  void **result; 

  result = a1;
  if ( *a1 )
  {
    free(*a1);
    result = a1;
    *a1 = 0;
  }
  return result;
}
signed int pxtnPulse_Noise::Allocate(_DWORD *a1, int a2, int a3)
{
  int v3; 
  signed int v5; 
  int i; 

  v5 = 0;
  a1[1] = a2;
  if ( pxtnNoise_zero_alloc((int)(a1 + 2), 76 * a2) )
  {
    for ( i = 0; i < a2; ++i )
    {
      v3 = a1[2] + 76 * i;
      *(_DWORD *)(v3 + 4) = a3;
      if ( !pxtnNoise_zero_alloc(v3 + 8, 8 * *(_DWORD *)(v3 + 4)) )
        goto LABEL_7;
    }
    v5 = 1;
  }
LABEL_7:
  if ( !v5 )
    pxtnPulse_Noise::Release(a1);
  return v5;
}
signed int Unused19(_DWORD *a1, int a2)
{
  int v2; 
  int v3; 
  int v4; 
  int v5; 
  int v6; 
  int v7; 
  int v8; 
  int v10; 
  int j; 
  int v12; 
  signed int v13; 
  int i; 

  v13 = 0;
  *a1 = *(_DWORD *)a2;
  a1[1] = *(_DWORD *)(a2 + 4);
  a1[2] = *(_DWORD *)(a2 + 8);
  a1[2] = 0;
  if ( a1[1] )
  {
    if ( !pxtnNoise_zero_alloc((int)(a1 + 2), 76 * a1[1]) )
      goto LABEL_11;
    for ( i = 0; i < a1[1]; ++i )
    {
      v10 = *(_DWORD *)(a2 + 8) + 76 * i;
      v12 = a1[2] + 76 * i;
      *(_DWORD *)v12 = *(_DWORD *)v10;
      *(_DWORD *)(v12 + 4) = *(_DWORD *)(v10 + 4);
      *(_DWORD *)(v12 + 12) = *(_DWORD *)(v10 + 12);
      v2 = v12 + 16;
      *(_DWORD *)v2 = *(_DWORD *)(v10 + 16);
      *(_DWORD *)(v2 + 4) = *(_DWORD *)(v10 + 20);
      *(_DWORD *)(v2 + 8) = *(_DWORD *)(v10 + 24);
      *(_DWORD *)(v2 + 12) = *(_DWORD *)(v10 + 28);
      *(_DWORD *)(v2 + 16) = *(_DWORD *)(v10 + 32);
      v3 = v12 + 36;
      *(_DWORD *)v3 = *(_DWORD *)(v10 + 36);
      *(_DWORD *)(v3 + 4) = *(_DWORD *)(v10 + 40);
      *(_DWORD *)(v3 + 8) = *(_DWORD *)(v10 + 44);
      *(_DWORD *)(v3 + 12) = *(_DWORD *)(v10 + 48);
      *(_DWORD *)(v3 + 16) = *(_DWORD *)(v10 + 52);
      v4 = v12 + 56;
      *(_DWORD *)v4 = *(_DWORD *)(v10 + 56);
      *(_DWORD *)(v4 + 4) = *(_DWORD *)(v10 + 60);
      *(_DWORD *)(v4 + 8) = *(_DWORD *)(v10 + 64);
      *(_DWORD *)(v4 + 12) = *(_DWORD *)(v10 + 68);
      *(_DWORD *)(v4 + 16) = *(_DWORD *)(v10 + 72);
      if ( !pxtnNoise_zero_alloc(v12 + 8, 8 * *(_DWORD *)(v12 + 4)) )
        goto LABEL_11;
      for ( j = 0; j < *(_DWORD *)(v10 + 4); ++j )
      {
        v5 = *(_DWORD *)(v10 + 8);
        v6 = *(_DWORD *)(v5 + 8 * j);
        v7 = *(_DWORD *)(v5 + 8 * j + 4);
        v8 = *(_DWORD *)(v12 + 8);
        *(_DWORD *)(v8 + 8 * j) = v6;
        *(_DWORD *)(v8 + 8 * j + 4) = v7;
      }
    }
  }
  v13 = 1;
LABEL_11:
  if ( !v13 )
    pxtnPulse_Noise::Release(a1);
  return v13;
}
void pxtnPulse_Frequency::Init()
{
  double oct_x24; 
  double v1; 
  double v2; 
  double v3; 
  double v4; 
  double v5; 
  double v6; 
  double v7; 
  double v8; 
  double v9; 
  double v10; 
  double v11; 
  double v12; 
  double v13; 
  double v14; 
  double v15; 
  double v16; 
  int key; 
  int f; 
  double work; 

  v1 = 0.00390625;
  v2 = 0.0078125;
  v3 = 0.015625;
  v4 = 0.03125;
  v5 = 0.0625;
  v6 = 0.125;
  v7 = 0.25;
  v8 = 0.5;
  v9 = 1.0;
  v10 = 2.0;
  v11 = 4.0;
  v12 = 8.0;
  v13 = 16.0;
  v14 = 32.0;
  v15 = 64.0;
  v16 = 128.0;
  oct_x24 = pxtnPulse_Frequency::_GetDivideOctaveRate(192);
  for ( f = 0; f < 3072; ++f )
  {
    work = *(&v1 + f / 192);
    for ( key = 0; key < f % 192; ++key )
      work = work * oct_x24;
    freq_table[f] = work;
  }
}

double pxtnPulse_Frequency::_GetDivideOctaveRate(int divi)
{
  signed int j; 
  signed int k; 
  double parameter; 
  double _result; 
  double add; 
  int l; 
  signed int i; 

  parameter = 1.0;
  
  for ( i = 0; i < 17; ++i )
  {
    
    add = 1.0;
    for ( j = 0; j < i; ++j )
      add = add * 0.1;
    
    for ( k = 0; k < 10; ++k )
    {
      
      _result = 1.0;
      for ( l = 0; l < divi; ++l )
      {
        _result = _result * ((double)k * add + parameter);
        if ( _result >= 2.0 )
          break;
      }
      
      if ( l != divi )
        break;
    }
    
    parameter = (double)(k - 1) * add + parameter;
  }
  return parameter;
}
double sub_428C20(int a1)
{
  int v2; 

  v2 = 16 * (a1 + 24576) / 256;
  if ( v2 < 0 )
    v2 = 0;
  if ( v2 >= 3072 )
    v2 = 3071;
  return freq_table[v2];
}

int pxtnPulse_Oscillator::ReadyGetSample(int a1, int a2, int a3, int a4, int a5)
{
  int result; 

  volume = a3;
  p_point = (pxtnPOINT *)a1;
  sample_num = a4;
  result = a2;
  point_num = a2;
  point_reso = a5;
  return result;
}


double pxtnPulse_Oscillator::GetOneSample_Overtone(signed int index)
{
  int o; 
  double work_double; 

  work_double = 0.0;
  for ( o = 0; o < point_num; ++o )
    work_double = sin(2.0 * 3.141592653589793 * (double)(signed int)p_point[o].x * (double)index / (double)sample_num)
                * (double)(signed int)p_point[o].y
                / (double)(signed int)p_point[o].x
                / 128.0
                + work_double;
  return (double)volume * work_double / 128.0;
}

double Unused20(int a1)
{
  int i; 
  int32_t v3; 
  int32_t v4; 
  double v5; 
  int v6; 
  int v7; 
  int32_t v8; 
  int32_t v9; 

  v6 = a1 * point_reso / sample_num;
  for ( i = 0; i < point_num && p_point[i].x <= v6; ++i )
    ;
  if ( i == point_num )
  {
    v3 = p_point[i - 1].x;
    v4 = *((_DWORD *)&p_point[i] - 1);
    v8 = point_reso;
    v9 = p_point->y;
  }
  else if ( i )
  {
    v3 = p_point[i - 1].x;
    v4 = *((_DWORD *)&p_point[i] - 1);
    v8 = p_point[i].x;
    v9 = p_point[i].y;
  }
  else
  {
    v3 = p_point->x;
    v4 = p_point->y;
    v8 = p_point->x;
    v9 = p_point->y;
  }
  v7 = v6 - v3;
  if ( v7 )
    v5 = (double)v4 + (double)(v9 - v4) * (double)v7 / (double)(v8 - v3);
  else
    v5 = (double)v4;
  return (double)volume * v5 / 128.0 / 128.0;
}


size_t WriteToFile(void *a1, size_t a2, size_t a3, FILE *a4)
{
  size_t v4; 

  _lock_file(a4);
  v4 = fwrite(a1, a2, a3, a4);
  _unlock_file(a4);
  return v4;
}


size_t ReadFromFile(void *a1, size_t a2, size_t a3, FILE *a4)
{
  size_t v4; 

  _lock_file(a4);
  v4 = fread(a1, a2, a3, a4);
  _unlock_file(a4);
  return v4;
}


int Unused21(int a1)
{
  int result; 

  result = dword_4507CC;
  dword_4507CC = a1;
  return result;
}

#error "429E39: positive sp value has been found (funcsize=0)"
int sub_42A3B8(int this)
{
  int result; 

  result = this;
  *(_DWORD *)(this + 4) = 0;
  *(_DWORD *)(this + 8) = 0;
  *(_DWORD *)this = &off_43CB00;
  return result;
}

void sub_42A450(int this)
{
  bool v1; 

  v1 = *(_DWORD *)(this + 8) == 0;
  *(_DWORD *)this = &off_43CB00;
  if ( !v1 )
    free(*(void **)(this + 4));
}

exception *__thiscall Unused23(exception *this, char *a2)
{
  exception *v2; 

  v2 = this;
  exception::exception(this, (const char *const *)&a2);
  *(_DWORD *)v2 = &off_43CB20;
  return v2;
}

_DWORD *__thiscall Unused24(_DWORD *this, int a2)
{
  _DWORD *v2; 

  v2 = this;
  exception::exception(a2);
  *v2 = &off_43CB20;
  return v2;
}


void sub_42A4A4(void *this)
{
  *(_DWORD *)this = &off_43CB20;
  sub_42A450((int)this);
}

exception *__thiscall sub_42A4AF(exception *this, char *a2)
{
  exception *v2; 

  v2 = this;
  exception::exception(this, (const char *const *)&a2);
  *(_DWORD *)v2 = &off_43CB2C;
  return v2;
}

_DWORD *__thiscall sub_42A4C8(_DWORD *this, int a2)
{
  _DWORD *v2; 

  v2 = this;
  exception::exception(a2);
  *v2 = &off_43CB2C;
  return v2;
}


void sub_42A4E0(int this)
{
  *(_DWORD *)this = &off_43CB2C;
  sub_42A450(this);
}

exception *__thiscall Unused25(exception *this, char *a2)
{
  exception *v2; 

  v2 = this;
  sub_42A4AF(this, a2);
  *(_DWORD *)v2 = &off_43CB38;
  return v2;
}

_DWORD *__thiscall Unused26(_DWORD *this, int a2)
{
  _DWORD *v2; 

  v2 = this;
  sub_42A4C8(this, a2);
  *v2 = &off_43CB38;
  return v2;
}

void sub_42A51B(void *this)
{
  *(_DWORD *)this = &off_43CB2C;
  sub_42A450((int)this);
}

void *__thiscall sub_42A526(void *this, char a2)
{
  void *v2; 

  v2 = this;
  sub_42A450((int)this);
  if ( a2 & 1 )
    j__free(v2);
  return v2;
}
void *__thiscall sub_42A561(void *this, char a2)
{
  void *v2; 

  v2 = this;
  sub_42A4A4(this);
  if ( a2 & 1 )
    j__free(v2);
  return v2;
}
void *__thiscall sub_42A57D(void *this, char a2)
{
  void *v2; 

  v2 = this;
  sub_42A4E0((int)this);
  if ( a2 & 1 )
    j__free(v2);
  return v2;
}
void *__thiscall sub_42A599(void *this, char a2)
{
  void *v2; 

  v2 = this;
  sub_42A51B(this);
  if ( a2 & 1 )
    j__free(v2);
  return v2;
}
char *__thiscall sub_42A66D(char *this)
{
  return this + 8;
}
void *__thiscall sub_42A671(void *this, int a2)
{
  void *result; 

  result = this;
  *(_DWORD *)this = &off_43CB44;
  return result;
}

void *__thiscall sub_42A67C(void *this, int a2)
{
  return this;
}
#error "42AC11: positive sp value has been found (funcsize=0)"
int sub_42BB2F(int a1)
{
  int result; 

  result = dword_4507E0;
  dword_4507E0 = a1;
  return result;
}

#error "42BB49: positive sp value has been found (funcsize=0)"
int sub_42BB4B(int a1)
{
  int result; 

  result = dword_4507E0;
  dword_4507E0 = a1;
  return result;
}

int __usercall sub_42BBA8@<eax>(_BYTE *a1@<eax>, char a2@<dh>, int a3, void *a4, int a5)
{
  _BYTE *v6; 

  *v6 ^= *a1 ^ a2;
  return _except_handler3(a3, a4, a5);
}
int sub_42BFAA()
{
  return flsall(1);
}

void **sub_42BFB3()
{
  return &off_441C38;
}

HANDLE sub_42DDF3()
{
  return hHeap;
}
void __noreturn sub_42DEB8()
{
  __crtExitProcess(0xFFu);
}
int sub_42EF36()
{
  return dword_450940;
}

void sub_42F2B2()
{
  nullsub_2();
}
void __noreturn sub_42FEB3()
{
  if ( off_442168 )
    off_442168();
  terminate();
}

int sub_42FF7A()
{
  lpTopLevelExceptionFilter = (FARPROC)SetUnhandledExceptionFilter(__CxxUnhandledExceptionFilter);
  return 0;
}
LPTOP_LEVEL_EXCEPTION_FILTER sub_42FF8D()
{
  return SetUnhandledExceptionFilter((LPTOP_LEVEL_EXCEPTION_FILTER)lpTopLevelExceptionFilter);
}
void sub_430F5B()
{
  void (**i)(void); 

  for ( i = (void (**)(void))&unk_43F204; i < (void (**)(void))&unk_43F204; ++i )
  {
    if ( *i )
      (*i)();
  }
}
void sub_430F9F()
{
  void (**i)(void); 

  for ( i = (void (**)(void))&dword_43F20C; i < (void (**)(void))&dword_43F20C; ++i )
  {
    if ( *i )
      (*i)();
  }
}

int sub_43283D(WORD CharType)
{
  void *v1; 

  v1 = *(void **)(_getptd() + 100);
  if ( v1 != off_44239C )
    LOBYTE(v1) = __updatetlocinfo();
  return __tolower_mt((CHAR)v1, CharType);
}

int sub_432B63(int a1, int a2)
{
  return _ld12cvt(a1, a2, &unk_44230C);
}

int sub_432B79(int a1, int a2)
{
  return _ld12cvt(a1, a2, &unk_442324);
}

int sub_432C0B(int a1, int a2)
{
  char v3; 
  char v4; 

  __strgtold12(&v4, &v3, a2, 0, 0, 0, 0);
  return sub_432B63((int)&v4, a1);
}

int sub_432C86(int a1, int a2)
{
  char v3; 
  char v4; 

  __strgtold12(&v4, &v3, a2, 0, 0, 0, 0);
  return sub_432B79((int)&v4, a1);
}

int sub_433364()
{
  return dword_450EE0;
}

void *sub_43336A()
{
  return &unk_450EE4;
}
int sub_433501()
{
  return 0;
}
int sub_434646(char a1)
{
  return x_ismbbtype(a1, 0, 1);
}

int __usercall sub_434866@<eax>(int a1@<ebp>)
{
  int v1; 
  int v2; 
  int v3; 
  int v5; 
  int v6; 
  int v7; 
  int v8; 
  int v9; 
  int v10; 
  int v11; 
  int v12; 
  int v13; 
  int v14; 

  v1 = *(_DWORD *)(a1 + 8);
  if ( v1 < uNumber && (v2 = 36 * (*(_DWORD *)(a1 + 8) & 0x1F), *(_BYTE *)(dword_450F00[v1 >> 5] + v2 + 4) & 1) )
  {
    _lock_fhandle(*(_DWORD *)(a1 + 8));
    *(_DWORD *)(a1 - 4) = 0;
    if ( *(_BYTE *)(dword_450F00[v1 >> 5] + v2 + 4) & 1 )
    {
      *(_DWORD *)(a1 - 28) = _chsize_lk(v1, *(_DWORD *)(a1 + 12));
    }
    else
    {
      *_errno() = 9;
      *(_DWORD *)(a1 - 28) = -1;
    }
    *(_DWORD *)(a1 - 4) = -1;
    sub_4348DF();
    v3 = *(_DWORD *)(a1 - 28);
  }
  else
  {
    *_errno() = 9;
  }
  return _SEH_epilog(v5, v6, v7, v8, v9, v10, v11, v12, v13, v14);
}

int sub_4348DF()
{
  return _unlock_fhandle();
}
int sub_434972(WORD CharType, int a2)
{
  void *v2; 

  v2 = *(void **)(_getptd() + 100);
  if ( v2 != off_44239C )
    v2 = (void *)__updatetlocinfo();
  return __isctype_mt((int)v2, CharType, a2);
}

int sub_4356F4()
{
  return _getptd() + 92;
}
size_t sub_43661D(char *a1, size_t a2, char *a3, struct tm *a4)
{
  return _Strftime(a1, a2, a3, a4, 0);
}
void **sub_436638()
{
  return off_44270C;
}

size_t sub_437328()
{
  return dword_442300;
}
int sub_437379()
{
  return 0;
}
int sub_43870F()
{
  return 0;
}
signed int sub_438A32(signed int a1, int a2)
{
  int v2; 
  signed int result; 
  signed int v4; 

  if ( a1 < uNumber && (v2 = 36 * (a1 & 0x1F), *(_BYTE *)(dword_450F00[a1 >> 5] + v2 + 4) & 1) )
  {
    _lock_fhandle(a1);
    if ( *(_BYTE *)(dword_450F00[a1 >> 5] + v2 + 4) & 1 )
    {
      v4 = _setmode_lk(a1, a2);
    }
    else
    {
      *_errno() = 9;
      v4 = -1;
    }
    _unlock_fhandle();
    result = v4;
  }
  else
  {
    *_errno() = 9;
    result = -1;
  }
  return result;
}

char *sub_439D59(char *a1)
{
  char *v1; 

  _lock(7);
  v1 = getenv(a1);
  _unlock(7);
  return v1;
}

void __noreturn sub_43A924()
{
  int (__stdcall **v0)(int); 
  char v1; 
  int v2; 

  sub_41FFA0(&v1, "invalid string position");
  v2 = 0;
  sub_41FAD0(&v0, (int)&v1);
  v0 = &off_43EF40;
  _CxxThrowException(&v0, &unk_43F298);
}


void __noreturn sub_43A964()
{
  int (__stdcall **v0)(int); 
  char v1; 
  int v2; 

  sub_41FFA0(&v1, "string too long");
  v2 = 0;
  sub_41FAD0(&v0, (int)&v1);
  v0 = &off_43EF34;
  _CxxThrowException(&v0, &unk_43F3E8);
}


int __usercall sub_43AC80@<eax>(int a1@<ebp>)
{
  return unknown_libname_5((void *)(a1 - 28));
}
_BYTE *__usercall sub_43ACA0@<eax>(int a1@<ebp>)
{
  return sub_41FC80((void *)(a1 - 80));
}
void __usercall sub_43ACC0(int a1@<ebp>)
{
  sub_42A450(*(_DWORD *)(a1 - 16));
}
void __usercall sub_43ACE0(int a1@<ebp>)
{
  sub_42A450(*(_DWORD *)(a1 - 16));
}
void __usercall sub_43AD00(int a1@<ebp>)
{
  sub_42A450(*(_DWORD *)(a1 - 16));
}
_BYTE *__usercall sub_43AD30@<eax>(int a1@<ebp>)
{
  return sub_41FC80((void *)(a1 - 80));
}
_BYTE *__usercall sub_43AD7A@<eax>(int a1@<ebp>)
{
  return sub_41FC80((void *)(a1 - 40));
}
int sub_43AD82(struct EHExceptionRecord *a1, struct EHRegistrationNode *a2, struct _CONTEXT *a3, void *a4)
{
  return __CxxFrameHandler(a1, a2, a3, a4);
}
_BYTE *__usercall sub_43AD8C@<eax>(int a1@<ebp>)
{
  return sub_41FC80((void *)(a1 - 40));
}
int sub_43AD94(struct EHExceptionRecord *a1, struct EHRegistrationNode *a2, struct _CONTEXT *a3, void *a4)
{
  return __CxxFrameHandler(a1, a2, a3, a4);
}

#error "There were 3 decompilation failure(s) on 641 function(s)"
