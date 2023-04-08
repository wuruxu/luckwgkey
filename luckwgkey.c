#include <stdio.h>
#include <string.h>
#include "wireguard.h"

int main(int argc, char* argv[]) {
  int b64strlen[256] = {0};
  if(argc > 0) {
    printf("generate wireguard public key by luckwgkey like as ");
    for(int i = 1; i < argc ; i++) {
      printf("%s ", argv[i]);
      b64strlen[i] = strlen(argv[i]);
    }
    printf("\n");

    printf("use \"Ctrl+C\" to quit in anytime \n\n");
  }

  do {
    wg_key privkey, pubkey;
    wg_key_b64_string b64_privkey, b64_pubkey;
    wg_generate_private_key(privkey);
    wg_key_to_base64(b64_privkey, privkey);

    wg_generate_public_key(pubkey, privkey);
    wg_key_to_base64(b64_pubkey, pubkey);
    for(int i = 1; i < argc; i++) {
      if(strncmp(b64_pubkey, argv[i], b64strlen[i]) == 0) {
        printf("* privkey = %s pubkey = %s\n", b64_privkey, b64_pubkey);
      }
    }
  } while(true);

  return 0;
}
