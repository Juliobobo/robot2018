const
  kp_teta : real;
  ki_teta : real;
  pi : real;
  
node Comportement
  (Cg: real;
  Cd: real;
  Mode: bool)
returns
  (v_d: real;
  v_g: real);

var
  V10_w_000: real;
  V13_w_003: real;
  V14_w_004: real;
  V17_w_007: real;
  V20_w_010: real;
  V100_w_000: real;
  V101_w_001: real;
  V102_w_002: real;
  V103_w_006: real;
  V104_w_007: real;
  V105_w_008: real;
  V106_w_009: real;
  V107_w_011: real;
  V108_w_012: real;
  V109_w_013: real;
  V110_w_014: real;
  V111_w_015: real;
  V112_w_016: real;
  V131_w_004: real;

let
  v_d = (if Mode then V17_w_007 else 0.400000);
  v_g = (if Mode then V14_w_004 else V20_w_010);
  V10_w_000 = ((pi / 200.000000) * V131_w_004);
  V13_w_003 = (Cd + Cg);
  V14_w_004 = (0.500000 * V109_w_013);
  V17_w_007 = (0.500000 * V110_w_014);
  V20_w_010 = (-1.000000 * 0.400000);
  V100_w_000 = (V102_w_002 + V101_w_001);
  V101_w_001 = (0.000000 -> (pre V100_w_000));
  V102_w_002 = (0.002000 * V10_w_000);
  V103_w_006 = (V112_w_016 + V111_w_015);
  V104_w_007 = ((-V106_w_009) + V107_w_011);
  V105_w_008 = (2.000000 * V104_w_007);
  V106_w_009 = (if (V108_w_012 < 0.000000) then (-V108_w_012) else V108_w_012);
  V107_w_011 = (0.005000 * V13_w_003);
  V108_w_012 = (2.000000 * V103_w_006);
  V109_w_013 = ((-V103_w_006) + V105_w_008);
  V110_w_014 = (V103_w_006 + V105_w_008);
  V111_w_015 = (kp_teta * V10_w_000);
  V112_w_016 = (ki_teta * V100_w_000);
  V131_w_004 = (Cd - Cg);
tel

