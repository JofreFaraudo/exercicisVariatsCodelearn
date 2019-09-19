import string
def create_dictionary(l1,l2):
    a = {}
    for i in range(len(l1)):
        a[l1[i]] = l2[i]
    return a
def alphabet_list():
    return [ i for i in string.lowercase[:26] ]
def old_pos(x,n,malphabet):
    return (x-n)-(malphabet*((x-n)/malphabet))
def new_pos(x,n,malphabet):
    return (x+n)-(malphabet*((x+n)/malphabet))
def encrypt_cesar(s,n,alphabet):
    result = ""
    for i in s:
        result += alphabet[new_pos(alphabet.index(i),n,len(alphabet))]
    return result
def decrypt_cesar(s,n,alphabet):
    result = ""
    for i in s:
        result += alphabet[old_pos(alphabet.index(i),n,len(alphabet))]
    return result
def new_alphabet(l,p):
    if len(p) > l or len(p) == 0:
        return l
    alphabet = list(p)
    lstChar = alphabet[-1]
    i = 0
    while(i<len(l)):
        char = l[(l.index(lstChar)+i)-(len(l)*((l.index(lstChar)+i)/len(l)))]
        if char not in alphabet:
        alphabet.append(char)
        i += 1
    return create_dictionary(l,alphabet)
def encrypt_monoalphabetic(s,kw,alphabet):
    ta = new_alphabet(alphabet,kw)
    ew = ""
    for i in s:
        ew += ta[i]
    return ew
def decrypt_monoalphabetic(s,kw,alphabet):
    ta = new_alphabet(alphabet,kw)
    dw = ""
    for i in s:
        for d,e in ta.items():
            if i == e:
                dw += d
    return dw
def displaced_alphabet(alphabet,n):
    return alphabet[n:] + alphabet[:n]
def create_displaced_alphabet_list(alphabet):
    return [ displaced_alphabet(alphabet,i) for i in range(len(alphabet)) ]
def create_encrypt_alphabets_dictionary(l1,l2):
    a = {}
    for i in range(len(l1)):
        a[l1[i]] = create_dictionary(l1,l2[i])
    return a
def create_decrypt_alphabets_dictionary(l1,l2):
    a = {}
    for i in range(len(l1)):
        a[l1[i]] = create_dictionary(l2[i],l1)
    return a
def encrypt_polyalphabetic(s,kw,l):
    ew = ""
    a = create_encrypt_alphabets_dictionary(l,create_displaced_alphabet_list(l))
    for i in range(len(s)):
        ew += a[kw[i-(len(kw)*(i/len(kw)))]][s[i]]
    return ew
def decrypt_polyalphabetic(s,kw,l):
    ew = ""
    a = create_decrypt_alphabets_dictionary(l,create_displaced_alphabet_list(l))
    for i in range(len(s)):
        ew += a[kw[i-(len(kw)*(i/len(kw)))]][s[i]]
    return ew
option = 0
num = 0
s = ""
functions = [encrypt_cesar,decrypt_cesar,encrypt_monoalphabetic,decrypt_monoalphabetic,encrypt_polyalphabetic,decrypt_polyalphabetic]
while option != 7:
option = raw_input("Menu\n====\n1. Encrypt cesar.\n2. Decrypt cesar.\n3. Encrypt monoalphabetic.\n4. Decrypt monoalphabetic.\n5. Encrypt polyalphabetic.\n6. Decrypt polyalphabetic.\n7. Exit.\nChoose option: ")
try:
option = int(option)
except:
print "Invalid option. Try again"
option = 0
else:
if option in range(1,7):
whackile len(s) == 0:
s = raw_input("Enter words: ")
result = ""
option -= 1
for w in s.split(" "):
num += 1
result += functions[option](w,1 if option < 2 else "clau",alphabet_list())+" "
result = result[:-1]
print result
s = ""
print "Thanks for using CRIPTOCODE. The total number of words treated has been: "+str(num)+"."