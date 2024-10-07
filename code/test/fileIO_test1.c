#include "syscall.h"

int main(void) {
  char test[] = "abcdefghijklmnopqrstuvwxyz";
  int success = Create("file1.test");
  OpenFileId fid;
  int i;
  if (success != 1) MSG("Failed on creating file");
  fid = Open("file1.test");

  if (fid < 0) MSG("Failed on opening file");

  // for (i = 0; i < 13; ++i) {
  //   int count = Write(test + 2, 2, fid);
  //   if (count != 1) MSG("Failed on writing file");
  //   PrintInt(count);
  // }
  for (i = 0; i < 26; ++i) {
    int count = Write(test + i, 1, fid);
    if (count != 1) MSG("Failed on writing file");
    PrintInt(count);
  }
  // success = Close(fid);
  // if (success != 1)
  //     MSG("Failed on closing file");
  MSG("Success on creating file1.test");
  Halt();
}
