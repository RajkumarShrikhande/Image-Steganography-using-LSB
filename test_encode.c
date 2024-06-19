#include <stdio.h>
#include <string.h>
#include "encode.h"
#include "types.h"
#include "common.h"
#include "decode.h"


int main(int argc, char *argv[])
{
    if(check_operation_type(argv) == e_encode)
    {
        printf("Selected encoding\n");
        EncodeInfo encInfo;
        if(read_and_validate_encode_args(argv, &encInfo) == e_success)
        {
            printf("INFO: Read and validate encode arguments is a success\n");
            if(do_encoding(&encInfo) == e_success)
            {
                printf("INFO: Encoding is Successful\n");
            }
            else
            {
                printf("INFO: Encoding was a failure\n");
            }
        }
        else
        {
            printf("INFO: Read and validate encode arguments was a failure\n");
            return 1;
        }
    }
    else if(check_operation_type(argv) == e_decode)
    {
        printf("Selected decoding\n");
        // Declare structure variables
        DecodeInfo decInfo;
        if (read_and_validate_decode_args(argv, &decInfo) == d_success)
        {
            printf("INFO: Read and validate decode arguments is a success\n");
         
            // Function call for do decoding
            if (do_decoding(&decInfo) == d_success)
            {
                printf("INFO: Decoding is Successful\n");
            }
            else
            {
                printf("INFO: Decoding failed\n");
            }
        }
        else
        {
            printf("INFO: Read and validate decode arguments is a failure\n");
             return 1;
        }
     }
    else
    {
        printf("Invalid input\nFor encoding:\n ./a.out -e beautiful.bmp secret.txt\nFor decoding:\n ./a.out -d stego.bmp");

    }
    return 0;

}

OperationType check_operation_type(char *argv[])
{
    if (strcmp(argv[1], "-e") == 0)
    {
        return e_encode;
    }
    else if (strcmp(argv[1], "-d") == 0)
    {
         return e_decode;
    }
    else
    {
        return e_unsupported;
    }
}
