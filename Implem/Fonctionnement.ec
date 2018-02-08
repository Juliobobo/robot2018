const
  minDistance : real;
  
node Fonctionnement
  (distance: real;
  Cd_n: real)
returns
  (Mode: bool);

var
  V7_w_001: bool;
  V9_w_003: bool;
  V10_w_004: bool;
  V11_w_005: bool;
  V12_w_006: bool;
  V13_w_007: bool;
  V14_w_008: bool;
  V15_w_009: bool;
  V16_w_010: bool;
  V17_w_011: bool;
  V66_w_000: bool;
  V67_w_003: bool;
  V68_w_004: bool;
  V77_w_000: bool;
  V78_w_003: bool;
  V79_w_004: bool;

let
  Mode = (not V10_w_004);
  V7_w_001 = (Cd_n < 50.000000);
  V9_w_003 = (false -> (pre V16_w_010));
  V10_w_004 = (V12_w_006 or V16_w_010);
  V11_w_005 = (V12_w_006 and V17_w_011);
  V12_w_006 = (distance < minDistance);
  V13_w_007 = (V14_w_008 and V7_w_001);
  V14_w_008 = (V77_w_000 and V78_w_003);
  V15_w_009 = (V66_w_000 and V67_w_003);
  V16_w_010 = (V15_w_009 and V17_w_011);
  V17_w_011 = (Cd_n > 50.000000);
  V66_w_000 = (not V9_w_003);
  V67_w_003 = (V13_w_007 or V68_w_004);
  V68_w_004 = (false -> (pre V15_w_009));
  V77_w_000 = (not V9_w_003);
  V78_w_003 = (V11_w_005 or V79_w_004);
  V79_w_004 = (false -> (pre V14_w_008));
tel

