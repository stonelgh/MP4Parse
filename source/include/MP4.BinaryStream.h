/*******************************************************************************
 * Copyright (c) 2011, Jean-David Gadina <macmade@eosgarden.com>
 * Distributed under the Boost Software License, Version 1.0.
 * 
 * Boost Software License - Version 1.0 - August 17th, 2003
 * 
 * Permission is hereby granted, free of charge, to any person or organization
 * obtaining a copy of the software and accompanying documentation covered by
 * this license (the "Software") to use, reproduce, display, distribute,
 * execute, and transmit the Software, and to prepare derivative works of the
 * Software, and to permit third-parties to whom the Software is furnished to
 * do so, all subject to the following:
 * 
 * The copyright notices in the Software and this entire statement, including
 * the above license grant, this restriction and the following disclaimer,
 * must be included in all copies of the Software, in whole or in part, and
 * all derivative works of the Software, unless such copies or derivative
 * works are solely in the form of machine-executable object code generated by
 * a source language processor.
 * 
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE, TITLE AND NON-INFRINGEMENT. IN NO EVENT
 * SHALL THE COPYRIGHT HOLDERS OR ANYONE DISTRIBUTING THE SOFTWARE BE LIABLE
 * FOR ANY DAMAGES OR OTHER LIABILITY, WHETHER IN CONTRACT, TORT OR OTHERWISE,
 * ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
 * DEALINGS IN THE SOFTWARE.
 ******************************************************************************/
 
/* $Id$ */

#ifndef _MP4_BINARY_STREAM_
#pragma once
#define _MP4_BINARY_STREAM_

#include "mp4.h"

namespace MP4
{
    class BinaryStreamException : public std::exception
    {
        private:
            
            
            
        protected:
            
            unsigned int code;
            
        public:
            
            enum
            {
                NoFileName = 0x00,
                OpenError  = 0x01
            };
            
            BinaryStreamException( void );
            BinaryStreamException( unsigned int c );
            virtual const char * what( void ) const throw();
    };
    
    class BinaryStream
    {
        private:
            
            
        protected:
            
            std::ifstream stream;
            
        public:
            
            BinaryStream( void );
            BinaryStream( char * filename );
            ~BinaryStream( void );
            
            uint8_t readUnsignedChar( void );
            int8_t readSignedChar( void );
                        
            uint16_t readUnsignedShort( void );
            int16_t readSignedShort( void );
            uint16_t readBigEndianUnsignedShort( void );
            uint16_t readLittleEndianUnsignedShort( void );
                        
            uint32_t readUnsignedInteger( void );
            int32_t readSignedInteger( void );
            uint32_t readBigEndianUnsignedInteger( void );
            uint32_t readLittleEndianUnsignedInteger( void );
                        
            uint64_t readUnsignedLong( void );
            int64_t readSignedLong( void );
            uint64_t readBigEndianUnsignedLong( void );
            uint64_t readLittleEndianUnsignedLong( void );
            
            float readFloat( void );
            double readDouble( void );
            
            float readBigEndianFixedPoint( unsigned int integerLength, unsigned int fractionalLength );
            float readLittleEndianFixedPoint( unsigned int integerLength, unsigned int fractionalLength );
            
            std::string * readBigEndianISO639Code( void );
            std::string * readNULLTerminatedString( void );
            std::string * readUTF8String( void );
            std::string * readLongUTF8String( void );
            
            bool good( void ) const;
            bool eof( void ) const;
            bool fail( void ) const;
            bool bad( void ) const;
            int peek( void );
            int get( void );
            int sync( void );
            std::streampos tellg( void );
            std::streamsize readsome( char * s, std::streamsize n );
            std::streamsize gcount( void ) const;
            std::istream & get( char & c );
            std::istream & get( char * s, std::streamsize n );
            std::istream & get( char * s, std::streamsize n, char delim );
            std::istream & get( std::streambuf & sb );
            std::istream & get( std::streambuf & sb, char delim );
            std::istream & getline(char * s, std::streamsize n );
            std::istream & getline(char * s, std::streamsize n, char delim );
            std::istream & ignore( std::streamsize n = 1, int delim = EOF );
            std::istream & read( char * s, std::streamsize n );
            std::istream & putback( char c );
            std::istream & unget( void );
            std::istream & seekg( std::streampos pos );
            std::istream & seekg( std::streamoff off, std::ios_base::seekdir dir );
    };
}

#endif /* MP4_BINARY_STREAM_ */
