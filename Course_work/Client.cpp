/** @file
 * @author Glebov I.D.
 * @version 2.4
 * @date 23.05.2023
 * @brief Client.cpp
 */
#include "Header.h"
/**
 * @brief Hashing.
 * @return Result hashing.
 * @param pass - Password.
 * @param salt - SALT.
 */
string Client::takeHash(string pass, string salt)
{
    string result, hashMsg, msg = salt+pass;
    HexEncoder encoder(new StringSink(result));
    Weak::MD5 hash;
    hash.Update((const byte*)&msg[0], msg.size());
    hashMsg.resize(hash.DigestSize());
    hash.Final((byte*)&hashMsg[0]);
    StringSource(hashMsg, true, new Redirector(encoder));
    cout << "Generated HASH: " << result << endl << endl;
    return result;
}