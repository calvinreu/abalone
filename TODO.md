 - find reason for error:  
  > undefined reference to `bool handle_input<(tile)0>(game const&, bool&, pair<signed char>&, unsigned char&, direction&)'
/usr/bin/ld: /home/calvinreu/Documents/abalone/UI/UI.cpp:36: undefined reference to `bool handle_input<(tile)1>(game const&, bool&, pair<signed char>&, unsigned char&, direction&)'
 - add a direction converter for the middle layer because top left dosen't stay top left
 - add side movement
 - create board image
 - render board