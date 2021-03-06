//#******************************************************************************
//#*
//#*      Copyright (C) 2015  Compro Computer Services
//#*      http://openig.compro.net
//#*
//#*      Source available at: https://github.com/CCSI-CSSI/MuseOpenIG
//#*
//#*      This software is released under the LGPL.
//#*
//#*   This software is free software; you can redistribute it and/or modify
//#*   it under the terms of the GNU Lesser General Public License as published
//#*   by the Free Software Foundation; either version 2.1 of the License, or
//#*   (at your option) any later version.
//#*
//#*   This software is distributed in the hope that it will be useful,
//#*   but WITHOUT ANY WARRANTY; without even the implied warranty of
//#*   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See
//#*   the GNU Lesser General Public License for more details.
//#*
//#*   You should have received a copy of the GNU Lesser General Public License
//#*   along with this library; if not, write to the Free Software
//#*   Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA 02111-1307 USA
//#*
//#*****************************************************************************
//#*	author    Trajce Nikolov Nick trajce.nikolov.nick@gmail.com
//#*	copyright(c)Compro Computer Services, Inc.

#include <Library-Protocol/losresponse.h>

using namespace OpenIG::Library::Protocol;

LOSResponse::LOSResponse()
{
}

int LOSResponse::write(OpenIG::Library::Networking::Buffer &buf) const
{
	buf << (unsigned char)opcode();
	buf << id;
	buf << position.x() << position.y() << position.z();
	buf << normal.x() << normal.y() << normal.z();

	return sizeof(unsigned char) + sizeof(unsigned int) + sizeof(osg::Vec3d::value_type) * 3 + sizeof(osg::Vec3f::value_type) * 3;
}

int LOSResponse::read(OpenIG::Library::Networking::Buffer &buf)
{
	unsigned char op;

	buf >> op;
	buf >> id;
	buf >> position.x() >> position.y() >> position.z();
	buf >> normal.x() >> normal.y() >> normal.z();

	return sizeof(unsigned char) + sizeof(unsigned int) + sizeof(osg::Vec3d::value_type) * 3 + sizeof(osg::Vec3f::value_type) * 3;
}