import numpy as np

N = 16
K = 16

B = ("0.840188 0.394383 0.783099 0.79844 0.911647 0.197551 0.335223 0.76823 0.277775 0.55397 0.477397 0.628871 0.364784 0.513401 0.95223 0.916195 0.635712 0.717297 0.141603 0.606969 0.0163006 0.242887 0.137232 0.804177 0.156679 0.400944 0.12979 0.108809 0.998924 0.218257 0.512932 0.839112 0.61264 0.296032 0.637552 0.524287 0.493583 0.972775 0.292517 0.771358 0.526745 0.769914 0.400229 0.891529 0.283315 0.352458 0.807725 0.919026 0.0697553 0.949327 0.525995 0.0860558 0.192214 0.663227 0.890233 0.348893 0.0641713 0.020023 0.457702 0.0630958 0.23828 0.970634 0.902208 0.85092 0.266666 0.53976 0.375207 0.760249 0.512535 0.667724 0.531606 0.0392803 0.437638 0.931835 0.93081 0.720952 0.284293 0.738534 0.639979 0.354049 0.687861 0.165974 0.440105 0.880075 0.829201 0.330337 0.228968 0.893372 0.35036 0.68667 0.956468 0.58864 0.657304 0.858676 0.43956 0.92397 0.398437 0.814767 0.684219 0.910972 0.482491 0.215825 0.950252 0.920128 0.14766 0.881062 0.641081 0.431953 0.619596 0.281059 0.786002 0.307458 0.447034 0.226107 0.187533 0.276235 0.556444 0.416501 0.169607 0.906804 0.103171 0.126075 0.495444 0.760475 0.984752 0.935004 0.684445 0.383188 0.749771 0.368664 0.29416 0.232262 0.584489 0.244413 0.15239 0.732149 0.125475 0.79347 0.164102 0.745071 0.0745298 0.950104 0.0525293 0.521563 0.176211 0.240062 0.797798 0.732654 0.656564 0.967405 0.639458 0.759735 0.0934805 0.134902 0.52021 0.0782321 0.0699064 0.204655 0.46142 0.819677 0.573319 0.755581 0.0519388 0.157807 0.999994 0.204329 0.889956 0.125468 0.997799 0.0540576 0.87054 0.0723288 0.00416161 0.923069 0.593892 0.180372 0.163132 0.39169 0.913027 0.819695 0.359095 0.552485 0.57943 0.452576 0.687387 0.0996401 0.530808 0.757294 0.304295 0.992228 0.576971 0.877614 0.747809 0.62891 0.0354209 0.747803 0.833239 0.925377 0.873271 0.831038 0.979434 0.743811 0.903366 0.983596 0.66688 0.497259 0.163968 0.830012 0.888949 0.0769947 0.649707 0.248044 0.62948 0.229137 0.70062 0.316867 0.328777 0.231428 0.074161 0.633072 0.223656 0.651132 0.510686 0.971466 0.280042 0.546107 0.719269 0.113281 0.471483 0.59254 0.944318 0.450918 0.336351 0.847684 0.434513 0.00323146 0.344943 0.598481 0.833243 0.233892 0.675476 0.48295 0.481936 0.304956 0.712087 0.182556 0.621823 0.0408643 0.413984 0.695984 0.673936 0.63764 0.347116 0.184622 0.609106 0.627158")
B = [float(i) for i in B.split()]

L = ("2.35245 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0.472348 9.40837 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0.412947 0.129128 4.8845 0 0 0 0 0 0 0 0 0 0 0 0 0 0.386353 0.0260052 0.0894759 0.488258 0 0 0 0 0 0 0 0 0 0 0 0 0.422502 0.312798 0.188315 0.315176 3.02225 0 0 0 0 0 0 0 0 0 0 0 0.141569 0.454764 0.158962 0.446159 0.364451 9.56611 0 0 0 0 0 0 0 0 0 0 0.127216 0.0546686 0.348871 0.379886 0.304678 0.0825076 0.117453 0 0 0 0 0 0 0 0 0 0.290024 0.421947 0.113406 0.407647 0.394295 0.0838242 0.320594 0.468473 0 0 0 0 0 0 0 0 0.328049 0.206947 0.0494288 0.417525 0.23136 0.471931 0.230323 0.419675 5.74214 0 0 0 0 0 0 0 0.381436 0.0612445 0.241871 0.0403976 0.00740345 0.106323 0.0187032 0.13462 0.160991 7.35147 0 0 0 0 0 0 0.0145053 0.465669 0.450081 0.020378 0.255693 0.372028 0.133784 0.16334 0.266323 0.217608 9.67868 0 0 0 0 0 0.289747 0.0456571 0.190881 0.339176 0.463182 0.422241 0.311107 0.193505 0.341916 0.0982139 0.074941 8.06322 0 0 0 0 0.340085 0.115339 0.410564 0.446408 0.134042 0.0451841 0.107399 0.00161552 0.0596894 0.0730677 0.451697 0.0800673 6.57522 0 0 0 0.323725 0.213851 0.492101 0.0900481 0.431459 0.476035 0.379795 0.477116 0.166916 0.218971 0.440298 0.089157 0.0300778 2.67607 0 0 0.431073 0.128292 0.208745 0.334234 0.468377 0.324083 0.244799 0.414784 0.458125 0.289983 0.022183 0.459741 0.349672 0.0952507 8.22875 0 0.429739 0.424012 0.235162 0.14359 0.416112 0.325211 0.0750494 0.392147 0.205006 0.0521655 0.0590632 0.423976 0.492464 0.14822 0.454054 2.52535 ")
L = [float(i) for i in L.split()]

X = ("-0.483034 -0.226735 -0.450213 -0.459032 -0.524117 -0.113575 -0.192723 -0.441664 -0.159696 -0.318484 -0.274461 -0.361545 -0.209719 -0.29516 -0.547448 -0.526731 0.148868 0.114402 0.0908261 0.141774 0.0899468 0.0449318 0.0470235 0.159811 0.0435316 0.0962198 0.0599898 0.0724169 0.141472 0.0728766 0.14666 0.177842 0.258393 0.121844 0.255726 0.23369 0.24722 0.230157 0.113266 0.278873 0.151951 0.245346 0.158142 0.283078 0.113702 0.153888 0.316648 0.332739 1.36896 2.51737 2.21989 1.34358 1.73393 1.61507 2.31127 1.82658 0.524899 0.835783 1.63332 1.03258 1.01598 2.73886 3.23422 3.06961 -0.0185086 -0.0716637 -0.0697496 0.146373 0.0373208 0.0493945 -0.0501156 -0.149661 0.0984178 0.240443 0.159961 0.156275 -0.00429367 -0.017125 -0.0839024 -0.168471 0.00454138 -0.101436 -0.0567754 0.0199292 0.00376183 -0.0469556 -0.0832174 0.00820526 0.00616345 0.0197026 0.0162956 0.00462476 0.0159792 -0.0389779 -0.105828 -0.0463473 -1.30418 -1.11754 -1.44788 2.75382 -1.80817 -4.06286 0.653886 1.88432 -0.998791 3.73204 -0.451331 -0.553652 1.8127 -6.56503 -3.89244 -7.34153 0.772695 -0.856793 -0.336644 -2.49087 1.06791 2.20502 -1.99 -0.756794 0.385929 -3.16691 -0.114765 1.0614 -0.0468833 4.20653 1.53019 3.40645 0.0472503 0.00761109 0.000217268 0.0259133 -0.00705169 -0.0683064 -0.00510482 -0.00315282 -0.00268435 0.160484 -0.0593208 0.00823847 -0.125415 -0.0609952 -0.146384 -0.0554423 0.0198544 0.0455293 0.121248 0.144829 0.0832003 0.092748 0.116307 0.114882 0.00809986 0.0658644 0.0744772 -0.00462274 0.00865449 -0.0359782 0.0484608 0.0678844 0.0414532 0.0964017 0.012093 -0.00815486 0.088794 0.024257 0.106437 -0.0230096 0.0974137 -0.0228825 0.0799572 -0.0254957 -0.0349982 0.103577 0.0707929 0.0391548 0.00301559 0.0186364 0.0987892 -0.00341193 0.0243267 0.103965 0.00619124 -0.0597675 0.0874737 -0.10794 0.0138962 0.0429794 -0.0648222 0.171836 0.0756378 0.204541 0.0449522 -0.0599514 -0.117441 -0.019557 0.040326 0.0835941 -0.0392659 -0.0215312 0.117678 -0.00867473 0.0278444 0.0860101 0.00832835 -0.00738128 -0.128025 0.0385777 0.322648 0.260895 0.441221 0.0630366 0.224928 0.171248 0.441167 -0.0666935 0.128313 0.028833 0.0115804 0.0526978 -0.193571 0.328242 0.382678 0.702264 -0.0136749 0.0518254 0.0692185 0.00338551 -0.00411465 0.00370128 0.106471 -0.0143214 0.0160309 0.107045 0.00372705 -0.08392 -0.0331196 -0.0510191 0.0388971 -0.0423728 0.113051 0.227381 0.181445 0.350354 0.0880896 -0.294359 0.39483 0.038946 0.0422706 0.566998 0.190978 0.0301085 0.0704857 -0.543457 -0.006096 -0.247743")
X = [float(i) for i in X.split()]

L = np.reshape(np.asarray(L), (N,N))
B = np.reshape(np.asarray(B), (N,K))
X = np.reshape(np.asarray(X), (N,K))

print "L"
print L
print "X"
print X
print "B"
print B
print np.dot(L,X) - B
