# RSA FileEncryptor
Simple file encryptor on C++

```
fileEncryptor - simple file encryptor, which supports decryption and key generation. It uses the RSA algorithm.
Required arguments:


Required    	Argument           Value                        Description

            --encrypt | -e	        -                  Encrypt mode. If not specified, the default mode of the encrypt.
            --decrypt | -d          -                  Decrypt mode. If not specified, the default mode of the encrypt.
            --generate-key | -g     -                  Generator keys mode. If not specified, the default mode of the encrypt.
    *       --in | -i          /path/to/file           Path to the encrypted file.
    *       --public-key       /path/to/public.key     Path to the public key.
    *       --private-key      /path/to/private.key    Path to the private key.
            --out | -o         /path/to/               Path, which will be located an encrypted file. If not specified, it will be located the output file in the current directory.
            --help | -h             -                  Print this information. Other arguments are ignored.
```
# RSA FileEncryptor
Простой шифратор файлов на C++

```
fileEncryptor - простой шифратор файлов, поддерживающий дешифрование и генерацию ключей. Использует алгоритм RSA. 
Необходимые аргументы:


Обязательный    	Аргумент	        Значение	                                 Описание

 	              --encrypt | -e	       -                  Режим шифратора. Если не указан, по умолчанию используется режим шифратора.
 	              --decrypt | -d	       -	              Режим дешифратора. Если не указан, по умолчанию используется режим шифратора.
                  --generate-key | -g	   -	              Режим генератора ключей. Если не указан, по умолчанию используется режим шифратора.
    *	          --in | -i	          /path/to/file	          Путь к шифруемому файлу.
    *	          --public-key	      /path/to/public.key	  Путь к публичному ключу.
    *	          --private-key	      /path/to/private.key	  Путь к приватному ключу.
 	              --out | -o          /path/to/	              Путь, в котором будет расположен зашифрованный файл. Если путь не указан, выходной файл будет расположен в текущем каталоге.
 	              --help | -h	             - 	              Распечать эту информацию. Другие аргументы  игнорируются.
```
