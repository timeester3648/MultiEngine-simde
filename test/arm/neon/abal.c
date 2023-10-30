#define SIMDE_TEST_ARM_NEON_INSN abal

#include "test-neon.h"
#include "../../../simde/arm/neon/abal.h"

/* https://community.intel.com/t5/Intel-C-Compiler/ICC-generates-incorrect-code/td-p/1199261 */
#if defined(HEDLEY_INTEL_VERSION)
#  define TEST_SIMDE_VABD_NO_TEST_32
#endif

static int
test_simde_vabal_s8 (SIMDE_MUNIT_TEST_ARGS) {
  static const struct {
    int16_t a[8];
    int8_t b[8];
    int8_t c[8];
    int16_t r[8];
  } test_vec[] = {
    { { -INT16_C(19874), -INT16_C(18252), INT16_C(2041), -INT16_C(14241), -INT16_C(30231), -INT16_C(13137), INT16_C(25586), -INT16_C(11143) },
      { INT8_C(56), INT8_C(55), -INT8_C(8), -INT8_C(66), -INT8_C(33), -INT8_C(97), -INT8_C(53), INT8_C(22) },
      { -INT8_C(18), INT8_C(11), INT8_C(45), -INT8_C(104), -INT8_C(124), INT8_C(12), INT8_C(47), -INT8_C(13) },
      { -INT16_C(19800), -INT16_C(18208), INT16_C(2094), -INT16_C(14203), -INT16_C(30140), -INT16_C(13028), INT16_C(25686), -INT16_C(11108) } },
    { { INT16_C(12066), INT16_C(17209), INT16_C(3127), INT16_C(28251), INT16_C(25395), -INT16_C(19511), INT16_C(16348), INT16_C(22812) },
      { -INT8_C(52), INT8_C(16), -INT8_C(7), INT8_C(8), -INT8_C(78), INT8_C(69), INT8_C(85), -INT8_C(11) },
      { INT8_C(19), -INT8_C(46), INT8_C(36), INT8_C(57), -INT8_C(58), -INT8_C(80), -INT8_C(33), -INT8_C(107) },
      { INT16_C(12137), INT16_C(17271), INT16_C(3170), INT16_C(28300), INT16_C(25415), -INT16_C(19362), INT16_C(16466), INT16_C(22908) } },
    { { -INT16_C(8280), INT16_C(25886), -INT16_C(25146), -INT16_C(15756), -INT16_C(1936), INT16_C(13944), -INT16_C(17993), -INT16_C(1374) },
      { -INT8_C(110), -INT8_C(69), -INT8_C(96), -INT8_C(10), INT8_C(103), -INT8_C(123), INT8_C(9), INT8_C(76) },
      { INT8_C(90), -INT8_C(2), -INT8_C(57), INT8_C(19), -INT8_C(106), -INT8_C(2), INT8_C(112), -INT8_C(61) },
      { -INT16_C(8080), INT16_C(25953), -INT16_C(25107), -INT16_C(15727), -INT16_C(1727), INT16_C(14065), -INT16_C(17890), -INT16_C(1237) } },
    { { -INT16_C(22536), -INT16_C(27437), INT16_C(12572), -INT16_C(8347), INT16_C(3077), -INT16_C(11369), INT16_C(17487), -INT16_C(10110) },
      { -INT8_C(127), INT8_C(18), INT8_C(0), INT8_C(65), -INT8_C(69), INT8_C(22), -INT8_C(76), INT8_C(61) },
      { -INT8_C(92), -INT8_C(67), -INT8_C(119), -INT8_C(118), INT8_C(125), -INT8_C(78), -INT8_C(66), INT8_C(105) },
      { -INT16_C(22501), -INT16_C(27352), INT16_C(12691), -INT16_C(8164), INT16_C(3271), -INT16_C(11269), INT16_C(17497), -INT16_C(10066) } },
    { { -INT16_C(30027), INT16_C(12670), INT16_C(8563), INT16_C(32381), -INT16_C(9412), INT16_C(16896), -INT16_C(12916), INT16_C(13214) },
      { INT8_C(62), INT8_C(59), -INT8_C(80), -INT8_C(71), INT8_C(23), INT8_C(20), -INT8_C(49), -INT8_C(9) },
      { INT8_C(89), -INT8_C(102), -INT8_C(63), INT8_C(9), INT8_C(38), -INT8_C(116), INT8_C(7), INT8_C(28) },
      { -INT16_C(30000), INT16_C(12831), INT16_C(8580), INT16_C(32461), -INT16_C(9397), INT16_C(17032), -INT16_C(12860), INT16_C(13251) } },
    { { INT16_C(23148), INT16_C(12510), -INT16_C(9344), INT16_C(9847), INT16_C(5308), INT16_C(16725), INT16_C(25730), -INT16_C(3498) },
      { INT8_C(19), -INT8_C(122), INT8_C(25), INT8_C(42), -INT8_C(70), -INT8_C(61), -INT8_C(91), -INT8_C(101) },
      { INT8_C(59), -INT8_C(111), INT8_C(36), INT8_C(1), INT8_C(70), INT8_C(77), INT8_C(51), INT8_C(31) },
      { INT16_C(23188), INT16_C(12521), -INT16_C(9333), INT16_C(9888), INT16_C(5448), INT16_C(16863), INT16_C(25872), -INT16_C(3366) } },
    { { INT16_C(688), -INT16_C(20307), -INT16_C(6465), -INT16_C(14204), -INT16_C(18860), -INT16_C(19839), INT16_C(11212), -INT16_C(9807) },
      { -INT8_C(94), INT8_C(1), -INT8_C(38), INT8_C(49), -INT8_C(107), INT8_C(57), INT8_C(28), INT8_C(17) },
      { -INT8_C(7), -INT8_C(32), INT8_C(99), INT8_C(54), INT8_C(32), INT8_C(122), -INT8_C(33), -INT8_C(108) },
      { INT16_C(775), -INT16_C(20274), -INT16_C(6328), -INT16_C(14199), -INT16_C(18721), -INT16_C(19774), INT16_C(11273), -INT16_C(9682) } },
    { { INT16_C(27280), -INT16_C(30706), INT16_C(20885), -INT16_C(11166), INT16_C(25965), INT16_C(12772), -INT16_C(23708), INT16_C(4767) },
      { INT8_C(101), INT8_C(87), -INT8_C(57), -INT8_C(17), INT8_C(109), INT8_C(49), INT8_C(52), INT8_C(15) },
      { INT8_C(10), -INT8_C(101), -INT8_C(10), INT8_C(37), -INT8_C(38), INT8_C(37), INT8_C(29), INT8_C(64) },
      { INT16_C(27371), -INT16_C(30518), INT16_C(20932), -INT16_C(11112), INT16_C(26112), INT16_C(12784), -INT16_C(23685), INT16_C(4816) } },
    { { INT16_C(23152), INT16_C(6589), -INT16_C(15056), INT16_C(20297), -INT16_C(19327), INT16_C(31683), INT16_C(16682), -INT16_C(5678) },
      { -INT8_C(11), INT8_C(65), INT8_C(24), INT8_C(107), -INT8_C(80), INT8_C(24), -INT8_C(126), -INT8_C(8) },
      { -INT8_C(56), -INT8_C(110), INT8_C(53), INT8_C(29), -INT8_C(60), INT8_C(121), INT8_C(106), -INT8_C(23) },
      { INT16_C(23197), INT16_C(6764), -INT16_C(15027), INT16_C(20375), -INT16_C(19307), INT16_C(31780), INT16_C(16914), -INT16_C(5663) } },
    { { INT16_C(10294), -INT16_C(5817), INT16_C(9100), INT16_C(15766), -INT16_C(19123), -INT16_C(22417), -INT16_C(23716), INT16_C(27840) },
      { INT8_C(69), -INT8_C(96), -INT8_C(8), -INT8_C(46), INT8_C(7), INT8_C(29), -INT8_C(27), -INT8_C(53) },
      { INT8_C(7), -INT8_C(102), -INT8_C(104), -INT8_C(70), INT8_C(113), INT8_C(44), INT8_C(29), INT8_C(30) },
      { INT16_C(10356), -INT16_C(5811), INT16_C(9196), INT16_C(15790), -INT16_C(19017), -INT16_C(22402), -INT16_C(23660), INT16_C(27923) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int16x8_t a = simde_vld1q_s16(test_vec[i].a);
    simde_int8x8_t b = simde_vld1_s8(test_vec[i].b);
    simde_int8x8_t c = simde_vld1_s8(test_vec[i].c);
    simde_int16x8_t r = simde_vabal_s8(a, b, c);

    simde_test_arm_neon_assert_equal_i16x8(r, simde_vld1q_s16(test_vec[i].r));
  }

  return 0;
}
static int
test_simde_vabal_s16 (SIMDE_MUNIT_TEST_ARGS) {
  static const struct {
    int32_t a[4];
    int16_t b[4];
    int16_t c[4];
    int32_t r[4];
  } test_vec[] = {
    { { INT32_C(18753146), -INT32_C(2003866889), -INT32_C(864249014), INT32_C(197306281) },
      { -INT16_C(3591), -INT16_C(31911), INT16_C(33), INT16_C(6612) },
      { INT16_C(18697), -INT16_C(23075), -INT16_C(2929), INT16_C(28306) },
      { INT32_C(18775434), -INT32_C(2003858053), -INT32_C(864246052), INT32_C(197327975) } },
    { { -INT32_C(1391144799), INT32_C(742148836), -INT32_C(551021601), -INT32_C(902833315) },
      { INT16_C(29949), -INT16_C(3952), -INT16_C(28825), INT16_C(26672) },
      { -INT16_C(23531), INT16_C(14887), -INT16_C(30022), INT16_C(30444) },
      { -INT32_C(1391091319), INT32_C(742167675), -INT32_C(551020404), -INT32_C(902829543) } },
    { { INT32_C(1063611766), INT32_C(441926320), INT32_C(1046962260), INT32_C(1303927204) },
      { INT16_C(10348), -INT16_C(6439), -INT16_C(20970), INT16_C(19505) },
      { INT16_C(4716), INT16_C(11699), INT16_C(12771), -INT16_C(11744) },
      { INT32_C(1063617398), INT32_C(441944458), INT32_C(1046996001), INT32_C(1303958453) } },
    { { -INT32_C(2143257679), INT32_C(992130135), -INT32_C(564197936), INT32_C(914997405) },
      { INT16_C(12394), -INT16_C(32081), -INT16_C(11761), INT16_C(27297) },
      { -INT16_C(1537), INT16_C(20301), INT16_C(19378), INT16_C(24912) },
      { -INT32_C(2143243748), INT32_C(992182517), -INT32_C(564166797), INT32_C(914999790) } },
    { { INT32_C(1220074826), -INT32_C(1351776494), INT32_C(358849784), -INT32_C(1057794144) },
      { INT16_C(31143), -INT16_C(13582), INT16_C(6266), INT16_C(28831) },
      { INT16_C(22705), -INT16_C(22522), INT16_C(23284), INT16_C(418) },
      { INT32_C(1220083264), -INT32_C(1351767554), INT32_C(358866802), -INT32_C(1057765731) } },
    { { -INT32_C(26502870), INT32_C(1549156435), -INT32_C(1940248725), -INT32_C(1018531254) },
      { -INT16_C(22625), -INT16_C(12680), -INT16_C(32610), -INT16_C(20348) },
      { INT16_C(26441), -INT16_C(4578), INT16_C(3566), -INT16_C(2362) },
      { -INT32_C(26453804), INT32_C(1549164537), -INT32_C(1940212549), -INT32_C(1018513268) } },
    { { INT32_C(294877544), INT32_C(393934723), INT32_C(2073567736), INT32_C(2036271058) },
      { -INT16_C(31824), -INT16_C(18526), INT16_C(6501), INT16_C(21343) },
      { INT16_C(17911), INT16_C(11406), INT16_C(12141), INT16_C(12247) },
      { INT32_C(294927279), INT32_C(393964655), INT32_C(2073573376), INT32_C(2036280154) } },
    { { -INT32_C(1298333974), INT32_C(2033301145), -INT32_C(1539477987), -INT32_C(806242335) },
      { -INT16_C(26396), -INT16_C(25530), INT16_C(25085), INT16_C(11920) },
      { -INT16_C(8236), -INT16_C(23934), INT16_C(2332), -INT16_C(5922) },
      { -INT32_C(1298315814), INT32_C(2033302741), -INT32_C(1539455234), -INT32_C(806224493) } },
    { { -INT32_C(408846521), -INT32_C(37450838), -INT32_C(549924034), -INT32_C(1806095098) },
      { INT16_C(27730), -INT16_C(4310), -INT16_C(7974), INT16_C(29047) },
      { INT16_C(13583), -INT16_C(31096), INT16_C(24025), -INT16_C(28181) },
      { -INT32_C(408832374), -INT32_C(37424052), -INT32_C(549892035), -INT32_C(1806037870) } },
    { { -INT32_C(1813757812), -INT32_C(1491300200), -INT32_C(1350343975), -INT32_C(370312500) },
      { INT16_C(27802), -INT16_C(5314), -INT16_C(26863), INT16_C(2157) },
      { INT16_C(32142), -INT16_C(1643), -INT16_C(11173), -INT16_C(19741) },
      { -INT32_C(1813753472), -INT32_C(1491296529), -INT32_C(1350328285), -INT32_C(370290602) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int32x4_t a = simde_vld1q_s32(test_vec[i].a);
    simde_int16x4_t b = simde_vld1_s16(test_vec[i].b);
    simde_int16x4_t c = simde_vld1_s16(test_vec[i].c);
    simde_int32x4_t r = simde_vabal_s16(a, b, c);

    simde_test_arm_neon_assert_equal_i32x4(r, simde_vld1q_s32(test_vec[i].r));
  }

  return 0;
}

static int
test_simde_vabal_s32 (SIMDE_MUNIT_TEST_ARGS) {
  static const struct {
    int64_t a[2];
    int32_t b[2];
    int32_t c[2];
    int64_t r[2];
  } test_vec[] = {
    { { INT32_C(6463005714558930663), -INT32_C(4139195320040793897) },
      { -INT16_C(98450158), INT16_C(1997215022) },
      { -INT16_C(225523203), -INT16_C(2057155643) },
      { INT32_C(6463005714686003708), -INT32_C(4139195315986423232) } },
    { { -INT32_C(5490267348749435227), -INT32_C(6047969120088065828) },
      { -INT16_C(632228442), INT16_C(723279817) },
      { -INT16_C(1854146244), INT16_C(131895829) },
      { -INT32_C(5490267347527517425), -INT32_C(6047969119496681840) } },
    { { INT32_C(5773633360489854601), -INT32_C(435070372727985286) },
      { -INT16_C(1405355634), INT16_C(197572179) },
      { INT16_C(1628245736), -INT16_C(100234158) },
      { INT32_C(5773633363523455971), -INT32_C(435070372430178949) } },
    { { INT32_C(6732792342444114720), -INT32_C(7148721497261387475) },
      { INT16_C(1275651916), INT16_C(1691872612) },
      { -INT16_C(318194444), -INT16_C(111152145) },
      { INT32_C(6732792344037961080), -INT32_C(7148721495458362718) } },
    { { -INT32_C(6633264670701156405), -INT32_C(317972272775361037) },
      { -INT16_C(1217485004), -INT16_C(1237626879) },
      { -INT16_C(1807669685), -INT16_C(957420452) },
      { -INT32_C(6633264670110971724), -INT32_C(317972272495154610) } },
    { { -INT32_C(1024963991674529220), INT32_C(8920714413382130185) },
      { INT16_C(734861933), -INT16_C(2036203191) },
      { INT16_C(1377486606), -INT16_C(2046018133) },
      { -INT32_C(1024963991031904547), INT32_C(8920714413391945127) } },
    { { -INT32_C(1523246057777963681), -INT32_C(684630109812294627) },
      { -INT16_C(988974737), INT16_C(2018160116) },
      { INT16_C(1290966707), -INT16_C(122305159) },
      { -INT32_C(1523246055498022237), -INT32_C(684630107671829352) } },
    { { -INT32_C(6520241241552503575), -INT32_C(2594711252795020607) },
      { -INT16_C(1529814204), INT16_C(2018427746) },
      { -INT16_C(375365442), -INT16_C(383088817) },
      { -INT32_C(6520241240398054813), -INT32_C(2594711250393504044) } },
    { { -INT32_C(4774129355393256012), INT32_C(2532618448657103471) },
      { INT16_C(2021007980), INT16_C(2144332610) },
      { INT16_C(1131868980), -INT16_C(2137550438) },
      { -INT32_C(4774129354504117012), INT32_C(2532618452938986519) } },
    { { -INT32_C(7043902067628191278), INT32_C(6145117476365756021) },
      { -INT16_C(656770654), INT16_C(846877590) },
      { -INT16_C(1349891154), INT16_C(513524804) },
      { -INT32_C(7043902066935070778), INT32_C(6145117476699108807) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int64x2_t a = simde_vld1q_s64(test_vec[i].a);
    simde_int32x2_t b = simde_vld1_s32(test_vec[i].b);
    simde_int32x2_t c = simde_vld1_s32(test_vec[i].c);
    simde_int64x2_t r = simde_vabal_s32(a, b, c);

    simde_test_arm_neon_assert_equal_i64x2(r, simde_vld1q_s64(test_vec[i].r));
  }

  return 0;
}

static int
test_simde_vabal_u8 (SIMDE_MUNIT_TEST_ARGS) {
  static const struct {
    uint16_t a[8];
    uint8_t b[8];
    uint8_t c[8];
    uint16_t r[8];
  } test_vec[] = {
    { { UINT16_C(10664), UINT16_C(44299), UINT16_C(38551), UINT16_C(60736), UINT16_C(8737), UINT16_C(35643), UINT16_C(18837), UINT16_C(7314) },
      { UINT8_C(135), UINT8_C(81), UINT8_C(246), UINT8_C(248), UINT8_C(90), UINT8_C(28), UINT8_C(55), UINT8_C(56) },
      { UINT8_C(213), UINT8_C(126), UINT8_C(65), UINT8_C(254), UINT8_C(93), UINT8_C(67), UINT8_C(230), UINT8_C(161) },
      { UINT16_C(10742), UINT16_C(44344), UINT16_C(38732), UINT16_C(60742), UINT16_C(8740), UINT16_C(35682), UINT16_C(19012), UINT16_C(7419) } },
    { { UINT16_C(21227), UINT16_C(59118), UINT16_C(5195), UINT16_C(38718), UINT16_C(55755), UINT16_C(41743), UINT16_C(5137), UINT16_C(60549) },
      { UINT8_C(39), UINT8_C(249), UINT8_C(204), UINT8_C(211), UINT8_C(75), UINT8_C(97), UINT8_C(65), UINT8_C(220) },
      { UINT8_C(192), UINT8_C(69), UINT8_C(200), UINT8_C(5), UINT8_C(70), UINT8_C(252), UINT8_C(159), UINT8_C(234) },
      { UINT16_C(21380), UINT16_C(59298), UINT16_C(5199), UINT16_C(38924), UINT16_C(55760), UINT16_C(41898), UINT16_C(5231), UINT16_C(60563) } },
    { { UINT16_C(49871), UINT16_C(50502), UINT16_C(4125), UINT16_C(28816), UINT16_C(63819), UINT16_C(14824), UINT16_C(10093), UINT16_C(58028) },
      { UINT8_C(65), UINT8_C(39), UINT8_C(223), UINT8_C(116), UINT8_C(85), UINT8_C(130), UINT8_C(126), UINT8_C(69) },
      { UINT8_C(134), UINT8_C(83), UINT8_C(45), UINT8_C(56), UINT8_C(89), UINT8_C(92), UINT8_C(105), UINT8_C(130) },
      { UINT16_C(49940), UINT16_C(50546), UINT16_C(4303), UINT16_C(28876), UINT16_C(63823), UINT16_C(14862), UINT16_C(10114), UINT16_C(58089) } },
    { { UINT16_C(44994), UINT16_C(36737), UINT16_C(35703), UINT16_C(49931), UINT16_C(54880), UINT16_C(24804), UINT16_C(60979), UINT16_C(12678) },
      { UINT8_C(60), UINT8_C(15), UINT8_C(6), UINT8_C(124), UINT8_C(223), UINT8_C(51), UINT8_C(224), UINT8_C(97) },
      { UINT8_C(59), UINT8_C(34), UINT8_C(92), UINT8_C(239), UINT8_C(103), UINT8_C(237), UINT8_C(161), UINT8_C(166) },
      { UINT16_C(44995), UINT16_C(36756), UINT16_C(35789), UINT16_C(50046), UINT16_C(55000), UINT16_C(24990), UINT16_C(61042), UINT16_C(12747) } },
    { { UINT16_C(47317), UINT16_C(36310), UINT16_C(62522), UINT16_C(33644), UINT16_C(50960), UINT16_C(30812), UINT16_C(31661), UINT16_C(11315) },
      { UINT8_C(58), UINT8_C(55), UINT8_C(114), UINT8_C(185), UINT8_C(194), UINT8_C(232), UINT8_C(232), UINT8_C(227) },
      { UINT8_C(87), UINT8_C(146), UINT8_C(233), UINT8_C(130), UINT8_C(193), UINT8_C(8), UINT8_C(47), UINT8_C(110) },
      { UINT16_C(47346), UINT16_C(36401), UINT16_C(62641), UINT16_C(33699), UINT16_C(50961), UINT16_C(31036), UINT16_C(31846), UINT16_C(11432) } },
    { { UINT16_C(54579), UINT16_C(43004), UINT16_C(21198), UINT16_C(851), UINT16_C(57477), UINT16_C(53281), UINT16_C(16237), UINT16_C(58376) },
      { UINT8_C(172), UINT8_C(116), UINT8_C(39), UINT8_C(251), UINT8_C(252), UINT8_C(159), UINT8_C(23), UINT8_C(47) },
      { UINT8_C(127), UINT8_C(45), UINT8_C(73), UINT8_C(173), UINT8_C(18), UINT8_C(211), UINT8_C(136), UINT8_C(220) },
      { UINT16_C(54624), UINT16_C(43075), UINT16_C(21232), UINT16_C(929), UINT16_C(57711), UINT16_C(53333), UINT16_C(16350), UINT16_C(58549) } },
    { { UINT16_C(25053), UINT16_C(34450), UINT16_C(60480), UINT16_C(35881), UINT16_C(33907), UINT16_C(62349), UINT16_C(58100), UINT16_C(6780) },
      { UINT8_C(210), UINT8_C(129), UINT8_C(167), UINT8_C(245), UINT8_C(228), UINT8_C(9), UINT8_C(181), UINT8_C(224) },
      { UINT8_C(110), UINT8_C(244), UINT8_C(216), UINT8_C(104), UINT8_C(142), UINT8_C(179), UINT8_C(10), UINT8_C(109) },
      { UINT16_C(25153), UINT16_C(34565), UINT16_C(60529), UINT16_C(36022), UINT16_C(33993), UINT16_C(62519), UINT16_C(58271), UINT16_C(6895) } },
    { { UINT16_C(40961), UINT16_C(17123), UINT16_C(34095), UINT16_C(2257), UINT16_C(63653), UINT16_C(21178), UINT16_C(64379), UINT16_C(1932) },
      { UINT8_C(18), UINT8_C(20), UINT8_C(44), UINT8_C(253), UINT8_C(36), UINT8_C(119), UINT8_C(60), UINT8_C(245) },
      { UINT8_C(155), UINT8_C(76), UINT8_C(6), UINT8_C(198), UINT8_C(3), UINT8_C(72), UINT8_C(174), UINT8_C(59) },
      { UINT16_C(41098), UINT16_C(17179), UINT16_C(34133), UINT16_C(2312), UINT16_C(63686), UINT16_C(21225), UINT16_C(64493), UINT16_C(2118) } },
    { { UINT16_C(22723), UINT16_C(1871), UINT16_C(24774), UINT16_C(28140), UINT16_C(7814), UINT16_C(37660), UINT16_C(46351), UINT16_C(34464) },
      { UINT8_C(23), UINT8_C(5), UINT8_C(191), UINT8_C(140), UINT8_C(70), UINT8_C(151), UINT8_C(171), UINT8_C(111) },
      { UINT8_C(16), UINT8_C(188), UINT8_C(232), UINT8_C(241), UINT8_C(125), UINT8_C(63), UINT8_C(45), UINT8_C(44) },
      { UINT16_C(22730), UINT16_C(2054), UINT16_C(24815), UINT16_C(28241), UINT16_C(7869), UINT16_C(37748), UINT16_C(46477), UINT16_C(34531) } },
    { { UINT16_C(61467), UINT16_C(22307), UINT16_C(43431), UINT16_C(6460), UINT16_C(60025), UINT16_C(283), UINT16_C(57097), UINT16_C(47111) },
      { UINT8_C(93), UINT8_C(41), UINT8_C(121), UINT8_C(132), UINT8_C(17), UINT8_C(218), UINT8_C(232), UINT8_C(137) },
      { UINT8_C(67), UINT8_C(243), UINT8_C(167), UINT8_C(162), UINT8_C(0), UINT8_C(109), UINT8_C(186), UINT8_C(166) },
      { UINT16_C(61493), UINT16_C(22509), UINT16_C(43477), UINT16_C(6490), UINT16_C(60042), UINT16_C(392), UINT16_C(57143), UINT16_C(47140) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint16x8_t a = simde_vld1q_u16(test_vec[i].a);
    simde_uint8x8_t b = simde_vld1_u8(test_vec[i].b);
    simde_uint8x8_t c = simde_vld1_u8(test_vec[i].c);
    simde_uint16x8_t r = simde_vabal_u8(a, b, c);

    simde_test_arm_neon_assert_equal_u16x8(r, simde_vld1q_u16(test_vec[i].r));
  }

  return 0;
}

static int
test_simde_vabal_u16 (SIMDE_MUNIT_TEST_ARGS) {
  static const struct {
    uint32_t a[4];
    uint16_t b[4];
    uint16_t c[4];
    uint32_t r[4];
  } test_vec[] = {
    { { UINT32_C(278395659), UINT32_C(1941798426), UINT32_C(4255697765), UINT32_C(152378613) },
      { UINT16_C(49641), UINT16_C(56497), UINT16_C(50497), UINT16_C(19047) },
      { UINT16_C(17963), UINT16_C(59142), UINT16_C(45415), UINT16_C(19420) },
      { UINT32_C(278427337), UINT32_C(1941801071), UINT32_C(4255702847), UINT32_C(152378986) } },
    { { UINT32_C(191395037), UINT32_C(2467241647), UINT32_C(348327967), UINT32_C(476956400) },
      { UINT16_C(9597), UINT16_C(36527), UINT16_C(39881), UINT16_C(38505) },
      { UINT16_C(37038), UINT16_C(46655), UINT16_C(32505), UINT16_C(60457) },
      { UINT32_C(191422478), UINT32_C(2467251775), UINT32_C(348335343), UINT32_C(476978352) } },
    { { UINT32_C(1964325848), UINT32_C(1604915231), UINT32_C(3007027398), UINT32_C(2332792010) },
      { UINT16_C(14280), UINT16_C(58599), UINT16_C(61512), UINT16_C(50992) },
      { UINT16_C(11364), UINT16_C(60872), UINT16_C(22758), UINT16_C(7476) },
      { UINT32_C(1964328764), UINT32_C(1604917504), UINT32_C(3007066152), UINT32_C(2332835526) } },
    { { UINT32_C(2263110539), UINT32_C(3056970276), UINT32_C(3871287446), UINT32_C(194424760) },
      { UINT16_C(41574), UINT16_C(21677), UINT16_C(31521), UINT16_C(62703) },
      { UINT16_C(40149), UINT16_C(56480), UINT16_C(34262), UINT16_C(23099) },
      { UINT32_C(2263111964), UINT32_C(3057005079), UINT32_C(3871290187), UINT32_C(194464364) } },
    { { UINT32_C(3351588884), UINT32_C(1336622885), UINT32_C(2607124568), UINT32_C(1120676337) },
      { UINT16_C(12982), UINT16_C(8142), UINT16_C(50577), UINT16_C(58333) },
      { UINT16_C(1510), UINT16_C(53160), UINT16_C(55474), UINT16_C(45308) },
      { UINT32_C(3351600356), UINT32_C(1336667903), UINT32_C(2607129465), UINT32_C(1120689362) } },
    { { UINT32_C(105325235), UINT32_C(2043500245), UINT32_C(660931095), UINT32_C(2087782248) },
      { UINT16_C(23050), UINT16_C(2095), UINT16_C(30017), UINT16_C(25573) },
      { UINT16_C(33778), UINT16_C(42100), UINT16_C(31297), UINT16_C(16723) },
      { UINT32_C(105335963), UINT32_C(2043540250), UINT32_C(660932375), UINT32_C(2087791098) } },
    { { UINT32_C(3666448686), UINT32_C(1737518001), UINT32_C(2117166043), UINT32_C(2831434639) },
      { UINT16_C(15849), UINT16_C(42751), UINT16_C(52907), UINT16_C(60502) },
      { UINT16_C(47667), UINT16_C(19672), UINT16_C(55976), UINT16_C(43385) },
      { UINT32_C(3666480504), UINT32_C(1737541080), UINT32_C(2117169112), UINT32_C(2831451756) } },
    { { UINT32_C(1945633868), UINT32_C(2322589051), UINT32_C(3344526250), UINT32_C(3462182855) },
      { UINT16_C(31637), UINT16_C(65145), UINT16_C(39492), UINT16_C(47509) },
      { UINT16_C(61957), UINT16_C(16067), UINT16_C(53834), UINT16_C(8288) },
      { UINT32_C(1945664188), UINT32_C(2322638129), UINT32_C(3344540592), UINT32_C(3462222076) } },
    { { UINT32_C(2740215773), UINT32_C(1595605772), UINT32_C(1329232400), UINT32_C(1788669758) },
      { UINT16_C(62367), UINT16_C(11982), UINT16_C(59626), UINT16_C(39780) },
      { UINT16_C(45250), UINT16_C(16979), UINT16_C(63502), UINT16_C(4905) },
      { UINT32_C(2740232890), UINT32_C(1595610769), UINT32_C(1329236276), UINT32_C(1788704633) } },
    { { UINT32_C(323341655), UINT32_C(721780532), UINT32_C(553402809), UINT32_C(755600971) },
      { UINT16_C(43978), UINT16_C(48707), UINT16_C(50941), UINT16_C(15969) },
      { UINT16_C(49159), UINT16_C(6730), UINT16_C(27676), UINT16_C(42935) },
      { UINT32_C(323346836), UINT32_C(721822509), UINT32_C(553426074), UINT32_C(755627937) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint32x4_t a = simde_vld1q_u32(test_vec[i].a);
    simde_uint16x4_t b = simde_vld1_u16(test_vec[i].b);
    simde_uint16x4_t c = simde_vld1_u16(test_vec[i].c);
    simde_uint32x4_t r = simde_vabal_u16(a, b, c);

    simde_test_arm_neon_assert_equal_u32x4(r, simde_vld1q_u32(test_vec[i].r));
  }

  return 0;
}

static int
test_simde_vabal_u32 (SIMDE_MUNIT_TEST_ARGS) {
  static const struct {
    uint64_t a[2];
    uint32_t b[2];
    uint32_t c[2];
    uint64_t r[2];
  } test_vec[] = {
    { { UINT64_C(4980484137400382401), UINT64_C(2266324244599854515) },
      { UINT32_C(1379797764), UINT32_C(1241159716) },
      { UINT32_C(2689520430), UINT32_C(2368067983) },
      { UINT64_C(4980484138710105067), UINT64_C(2266324245726762782) } },
    { { UINT64_C(9009389137652207759), UINT64_C(1405495345318952109) },
      { UINT32_C(2165735875), UINT32_C(2844963172) },
      { UINT32_C(3450596080), UINT32_C(1410269298) },
      { UINT64_C(9009389138937067964), UINT64_C(1405495346753645983) } },
    { { UINT64_C(7946017522271812169), UINT64_C(5954939470930688449) },
      { UINT32_C(3977955336), UINT32_C(406581886) },
      { UINT32_C(1202180194), UINT32_C(901550917) },
      { UINT64_C(7946017525047587311), UINT64_C(5954939471425657480) } },
    { { UINT64_C(2075730948399881393), UINT64_C(6233083028381432090) },
      { UINT32_C(523472130), UINT32_C(3276876363) },
      { UINT32_C(575692398), UINT32_C(4111243132) },
      { UINT64_C(2075730948452101661), UINT64_C(6233083029215798859) } },
    { { UINT64_C(2039151327536943025), UINT64_C(675987598434364761) },
      { UINT32_C(1678761089), UINT32_C(1601877560) },
      { UINT32_C(952491186), UINT32_C(4222480985) },
      { UINT64_C(2039151328263212928), UINT64_C(675987601054968186) } },
    { { UINT64_C(4375299356301599279), UINT64_C(3073299433347657432) },
      { UINT32_C(2307356223), UINT32_C(1411192556) },
      { UINT32_C(3885690105), UINT32_C(1683393261) },
      { UINT64_C(4375299357879933161), UINT64_C(3073299433619858137) } },
    { { UINT64_C(3125622259840841973), UINT64_C(4157966308493685739) },
      { UINT32_C(607311755), UINT32_C(1883176105) },
      { UINT32_C(4005499408), UINT32_C(2467576142) },
      { UINT64_C(3125622263239029626), UINT64_C(4157966309078085776) } },
    { { UINT64_C(882865717690512135), UINT64_C(8325625789344375595) },
      { UINT32_C(2171229385), UINT32_C(3654125095) },
      { UINT32_C(1809428305), UINT32_C(1627714497) },
      { UINT64_C(882865718052313215), UINT64_C(8325625791370786193) } },
    { { UINT64_C(6491931873381893843), UINT64_C(4899321772001859037) },
      { UINT32_C(2294161292), UINT32_C(1861598823) },
      { UINT32_C(3870176055), UINT32_C(2719169208) },
      { UINT64_C(6491931874957908606), UINT64_C(4899321772859429422) } },
    { { UINT64_C(3868657064471156875), UINT64_C(1209768485240087287) },
      { UINT32_C(4258016166), UINT32_C(673492032) },
      { UINT32_C(1831741569), UINT32_C(3551386843) },
      { UINT64_C(3868657066897431472), UINT64_C(1209768488117982098) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint64x2_t a = simde_vld1q_u64(test_vec[i].a);
    simde_uint32x2_t b = simde_vld1_u32(test_vec[i].b);
    simde_uint32x2_t c = simde_vld1_u32(test_vec[i].c);
    simde_uint64x2_t r = simde_vabal_u32(a, b, c);

    simde_test_arm_neon_assert_equal_u64x2(r, simde_vld1q_u64(test_vec[i].r));
  }

  return 0;
}


SIMDE_TEST_FUNC_LIST_BEGIN
SIMDE_TEST_FUNC_LIST_ENTRY(vabal_s8)
SIMDE_TEST_FUNC_LIST_ENTRY(vabal_s16)
SIMDE_TEST_FUNC_LIST_ENTRY(vabal_s32)
SIMDE_TEST_FUNC_LIST_ENTRY(vabal_u8)
SIMDE_TEST_FUNC_LIST_ENTRY(vabal_u16)
SIMDE_TEST_FUNC_LIST_ENTRY(vabal_u32)
SIMDE_TEST_FUNC_LIST_END

#include "test-neon-footer.h"