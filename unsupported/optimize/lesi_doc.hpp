static void lsei_(double *C_mat, double *D_vec, double *E_mat, double *F_vec, double *G_mat,
                  double *H_vec, int lc_eq_mat_rows, int mc_eq_mat_rows, int le_prob_mat_rows, int me_prob_mat_rows, int lg_ineq_mat_rows,
                  int mg_ineq_mat_rows, int n, double *x, double *xnrm, double *w_lagrange_mul, int *jw,
                  int *mode) {
    /* Initialized data */

    const double epmach = 2.22e-16;

    /* System generated locals */
    int c_dim1, c_offset, e_dim1, e_offset, g_dim1, g_offset, i__1, i__2, i__3;
    double d__1;

    /* Local variables */
    int i, j, k, l;
    double t;
    int ie, if__, ig, iw, mc1;
    int krank;

    /*     FOR MODE=1, THE SUBROUTINE RETURNS THE SOLUTION X OF */
    /*     EQUALITY & INEQUALITY CONSTRAINED LEAST SQUARES PROBLEM LSEI : */
    /*                MIN ||E_mat*X - F_vec|| */
    /*                 X */
    /*                S.T.  C_mat*X  = D_vec, */
    /*                      G_mat*X >= H_vec. */
    /*     USING QR DECOMPOSITION & ORTHOGONAL BASIS OF NULLSPACE OF C_mat */
    /*     CHAPTER 23.6 OF LAWSON & HANSON: SOLVING LEAST SQUARES PROBLEMS. */
    /*     THE FOLLOWING DIMENSIONS OF THE ARRAYS DEFINING THE PROBLEM */
    /*     ARE NECESSARY */
    /*     DIM(E_mat) :   FORMAL (LE,N),    ACTUAL (ME,N) */
    /*     DIM(F_vec) :   FORMAL (LE  ),    ACTUAL (ME  ) */
    /*     DIM(C_mat) :   FORMAL (LC,N),    ACTUAL (MC,N) */
    /*     DIM(D_vec) :   FORMAL (LC  ),    ACTUAL (MC  ) */
    /*     DIM(G_mat) :   FORMAL (LG,N),    ACTUAL (MG,N) */
    /*     DIM(H_vec) :   FORMAL (LG  ),    ACTUAL (MG  ) */
    /*     DIM(X) :   FORMAL (N   ),    ACTUAL (N   ) */
    /*     DIM(W) :   2*MC+ME+(ME+MG)*(N-MC)  for LSEI */
    /*              +(N-MC+1)*(MG+2)+2*MG     for LSI */
    /*     DIM(JW):   MAX(MG,L) */
    /*     ON ENTRY, THE USER HAS TO PROVIDE THE ARRAYS C_mat, D_vec, E_mat, F_vec, G_mat, AND H_vec. */
    /*     ON RETURN, ALL ARRAYS WILL BE CHANGED BY THE SUBROUTINE. */
    /*     X     STORES THE SOLUTION VECTOR */
    /*     XNORM STORES THE RESIDUUM OF THE SOLUTION IN EUCLIDIAN NORM */
    /*     W     STORES THE VECTOR OF LAGRANGE MULTIPLIERS IN ITS FIRST */
    /*           MC+MG ELEMENTS */
    /*     MODE  IS A SUCCESS-FAILURE FLAG WITH THE FOLLOWING MEANINGS: */
    /*          MODE=1: SUCCESSFUL COMPUTATION */
    /*               2: ERROR RETURN BECAUSE OF WRONG DIMENSIONS (N<1) */
    /*               3: ITERATION COUNT EXCEEDED BY NNLS */
    /*               4: INEQUALITY CONSTRAINTS INCOMPATIBLE */
    /*               5: MATRIX E_mat IS NOT OF FULL RANK */
    /*               6: MATRIX C_mat IS NOT OF FULL RANK */
    /*               7: RANK DEFECT IN HFTI */
    /*     18.5.1981, DIETER KRAFT, DFVLR OBERPFAFFENHOFEN */
    /*     20.3.1987, DIETER KRAFT, DFVLR OBERPFAFFENHOFEN */
    /* Parameter adjustments */
    --D_vec;
    --F_vec;
    --H_vec;
    --x;
    g_dim1 = lg_ineq_mat_rows;
    g_offset = 1 + g_dim1;
    G_mat -= g_offset;
    e_dim1 = le_prob_mat_rows;
    e_offset = 1 + e_dim1;
    E_mat -= e_offset;
    c_dim1 = lc_eq_mat_rows;
    c_offset = 1 + c_dim1;
    C_mat -= c_offset;
    --w_lagrange_mul;
    --jw;

    /* Function Body */
    *mode = 2;
    if (mc_eq_mat_rows > n) {
        goto L75_RETURN;;
    }
    l = n - mc_eq_mat_rows;
    mc1 = mc_eq_mat_rows + 1;
    iw = (l + 1) * (mg_ineq_mat_rows + 2) + (mg_ineq_mat_rows << 1) + mc_eq_mat_rows;
    ie = iw + mc_eq_mat_rows + 1;
    if__ = ie + me_prob_mat_rows * l;
    ig = if__ + me_prob_mat_rows;
    /*  TRIANGULARIZE C_mat AND APPLY FACTORS TO E_mat AND G_mat */

    for (i = 1; i <= mc_eq_mat_rows; ++i) {
        /* Computing MIN */

        j = MIN2(i + 1, lc_eq_mat_rows);
        // i__2 = i + 1;
        // i__3 = mc_eq_mat_rows - i;
        householder_transformation(1, i, i+1, n, &C_mat[i + c_dim1], lc_eq_mat_rows, &w_lagrange_mul[iw + i],
            &C_mat[j + c_dim1], lc_eq_mat_rows, 1, mc_eq_mat_rows - i);
        // i__2 = i + 1;
        householder_transformation(2, i, i+1, n, &C_mat[i + c_dim1], lc_eq_mat_rows, &w_lagrange_mul[iw + i],
            &E_mat[e_offset], le_prob_mat_rows, 1, me_prob_mat_rows);
        /* L10: */
        // i__2 = i + 1;
        householder_transformation(2, i, i+1, n, &C_mat[i + c_dim1], lc_eq_mat_rows, &w_lagrange_mul[iw + i],
            &G_mat[g_offset], lg_ineq_mat_rows, 1, mg_ineq_mat_rows);
    }
    /*  SOLVE C_mat*X=D_vec AND MODIFY F_vec */
    *mode = 6;
    for(i = 1; i <= mc_eq_mat_rows; i++) {
        if ((d__1 = C_mat[i + i * c_dim1], fabs(d__1)) < epmach) {
            goto L75_RETURN;
        }
        // i__1 = i - 1;
        x[i] = (D_vec[i] - ddot_sl__(i-1, &C_mat[i + c_dim1], lc_eq_mat_rows, &x[1], 1)) / C_mat[i + i * c_dim1];
        /* L15: */
    }
    *mode = 1;
    // w_lagrange_mul[mc1] = 0.0;
    // i__2 = mg_ineq_mat_rows; /* BUGFIX for mc_eq_mat_rows == n: changed from mg_ineq_mat_rows - mc_eq_mat_rows, SGJ 2010 */
    // dcopy___(&i__2, &w_lagrange_mul[mc1], 0, &w_lagrange_mul[mc1], 1);
    w_lagrange_mul.segment(mc1, mg_ineq_mat_rows) = vector::zero();
    if (mc_eq_mat_rows == n) {
        goto L50;
    }
    for(i = 1; i <= me_prob_mat_rows; i++) {
        /* L20: */
        w_lagrange_mul[if__ - 1 + i] = F_vec[i] - ddot_sl__(mc_eq_mat_rows, &E_mat[i + e_dim1], le_prob_mat_rows, &x[1], 1);
    }
    /*  STORE TRANSFORMED E_mat & G_mat */

    for(i = 1; i <= me_prob_mat_rows; i++) {
        /* L25: */
        dcopy___(&l, &E_mat[i + mc1 * e_dim1], le_prob_mat_rows, &w_lagrange_mul[ie - 1 + i], me_prob_mat_rows);
    }
    // w_lagrange_mul.segment(?,?) = E_mat
    for(i = 1; i <= mg_ineq_mat_rows; i++) {
        /* L30: */
        dcopy___(&l, &G_mat[i + mc1 * g_dim1], lg_ineq_mat_rows, &w_lagrange_mul[ig - 1 + i], mg_ineq_mat_rows);
    }
    if (mg_ineq_mat_rows > 0) {
        goto L40;
    }
    /*  SOLVE LS WITHOUT INEQUALITY CONSTRAINTS */
    *mode = 7;
    k = MAX2(le_prob_mat_rows, n);
    t = sqrt(epmach);
    hfti_(&w_lagrange_mul[ie], me_prob_mat_rows, me_prob_mat_rows, &l, &w_lagrange_mul[if__], &k, 1, &t, &krank, xnrm, &w_lagrange_mul[1],
            &w_lagrange_mul[l + 1], &jw[1]);
    dcopy___(&l, &w_lagrange_mul[if__], 1, &x[mc1], 1);
    if (krank != l) {
        goto L75_RETURN;;
    }
    *mode = 1;
    goto L50;
    /*  MODIFY H_vec AND SOLVE INEQUALITY CONSTRAINED LS PROBLEM */
    L40:
    for(i = 1; i <= mg_ineq_mat_rows; i++) {
        /* L45: */
        H_vec[i] -= ddot_sl__(mc_eq_mat_rows, &G_mat[i + g_dim1], lg_ineq_mat_rows, &x[1], 1);
    }
    lsi_(&w_lagrange_mul[ie], &w_lagrange_mul[if__], &w_lagrange_mul[ig], &H_vec[1], me_prob_mat_rows, me_prob_mat_rows, mg_ineq_mat_rows, mg_ineq_mat_rows, &l, &x[mc1], xnrm,
        &w_lagrange_mul[mc1], &jw[1], mode);
    if (mc_eq_mat_rows == 0) {
        goto L75_RETURN;;
    }
    t = dnrm2___(mc_eq_mat_rows, &x[1], 1);
    *xnrm = sqrt(*xnrm * *xnrm + t * t);
    if (*mode != 1) {
        goto L75_RETURN;;
    }
    /*  SOLUTION OF ORIGINAL PROBLEM AND LAGRANGE MULTIPLIERS */
    L50:
    for(i = 1; i <= me_prob_mat_rows; i++) {
        /* L55: */
        F_vec[i] = ddot_sl__(n, &E_mat[i + e_dim1], le_prob_mat_rows, &x[1], 1) - F_vec[i];
    }
    for(i = 1; i <= mc_eq_mat_rows; i++) {
        /* L60: */
        D_vec[i] = ddot_sl__(me_prob_mat_rows, &E_mat[i * e_dim1 + 1], 1, &F_vec[1], 1) -
                ddot_sl__(mg_ineq_mat_rows, &G_mat[i * g_dim1 + 1], 1, &w_lagrange_mul[mc1], 1);
    }
    for (i = mc_eq_mat_rows; i >= 1; --i) {
        /* L65: */
        i__2 = i + 1;
        householder_transformation(2, &i, &i__2, n, &C_mat[i + c_dim1], lc_eq_mat_rows, &w_lagrange_mul[iw + i], &x[1],
            1, 1, 1);
    }
    for (i = mc_eq_mat_rows; i >= 1; --i) {
        /* Computing MIN */
        i__2 = i + 1;
        j = MIN2(i__2, lc_eq_mat_rows);
        i__2 = mc_eq_mat_rows - i;
        w_lagrange_mul[i] =
            (D_vec[i] - ddot_sl__(&i__2, &C_mat[j + i * c_dim1], 1, &w_lagrange_mul[j], 1)) /
            C_mat[i + i * c_dim1];
        /* L70: */
    }
    /*  END OF SUBROUTINE LSEI */
    L75_RETURN;:
    return;
} /* lsei_ */