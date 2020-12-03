! Gaussian sample calculation.
!
! This is a comment line, which always begins with
! an exclamation mark.
! See https://gaussian.com/input for explanation of
! Gaussian input format.
%mem=250MB
%chk=H2O_opt_RHF_cc-pVDZ.chk

#RHF/cc-pVDZ  5D  7F  units=AU opt

H2O RHF with cc-pVDZ basis (geometry optimization)

0,1
O      0.0000000   0.0000000   -0.0090000
H      0.0000000   1.5152630   -1.0588980
H      0.0000000  -1.5152630   -1.0588980

