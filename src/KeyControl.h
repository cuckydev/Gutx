ButtonConfig *ResetKeyboardConfig(ButtonConfig *a1);
ButtonConfig *ResetJoystickConfig(ButtonConfig *a1);
ButtonConfig *ResetButtonConfig(int a1);
int WriteButtonConfig(void *a1);
int ReadButtonConfig(void *a1);
ButtonConfig *LoadButtonConfig();