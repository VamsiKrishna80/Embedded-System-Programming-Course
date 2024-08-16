volatile int *dirF,*dirK,*outputF,*inputF,*outputK,*inputK;
void init_PORTF(int x)
{
  inputF=0x2f;
  outputF=0x31;
   dirF=0x30;
   *dirF=x;
}
void init_PORTK(int x)
{
  inputK=0x106;
  outputK=0x108;
   dirK=0x107;
   *dirK=x;
}
/*void GlowLEDs8()
{
   volatile int outputmode=0xff;
  init_PORTF(outputmode);
  *outputF=0xff;
}
*/