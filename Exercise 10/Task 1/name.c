/* This is the decompiled C-file we get from Ghidra.
   It is not obvious at first, but this program is vulnerable to
   Format string attacks.
   This is because printf will interpret parameters (such as %s, %d, and %p)
   from the input buffer as commands. This can allow an attacker to read from the program stack, not good.
   To see the fix; se the fime 'name_fixed.c */

undefined8 main(void)

{
  char local_28 [32];
  
  printf("Enter your name: ");
  fgets(local_28,0x20,stdin);
  printf("Hello ");
  printf(local_28);
  putchar(10);
  return 0;
}

