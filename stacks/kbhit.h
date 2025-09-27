#ifndef KBHITh
#define KBHITh

#ifdef __cplusplus
extern "C" {
#endif  // __cplusplus


void inti_keyboard( void );
void close_keyboard( void );
unsigned char kbhit( void );
int readch( void );


#ifdef __cplusplus
}
#endif  // __cplusplus

#endif

