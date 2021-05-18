import unicodedata

def remove_accents(input_str):
    nfkd_form = unicodedata.normalize('NFKD', input_str)
    only_ascii = nfkd_form.encode('ASCII', 'ignore')
    return only_ascii

def main():
    inputF = open("lusiadas.txt", "r")
    outputF = open("lusiadas_clean.txt", "w")

    output_str = b''
    for elem in inputF.read():
        output_str+= remove_accents(elem)

    outputF.write(output_str.decode('utf8'))
    
    inputF.close()
    outputF.close()

main()
