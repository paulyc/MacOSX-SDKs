/*
 * Copyright (c) 2000-2003 Apple Computer, Inc. All rights reserved.
 *
 * @APPLE_LICENSE_HEADER_START@
 * 
 * This file contains Original Code and/or Modifications of Original Code
 * as defined in and that are subject to the Apple Public Source License
 * Version 2.0 (the 'License'). You may not use this file except in
 * compliance with the License. Please obtain a copy of the License at
 * http://www.opensource.apple.com/apsl/ and read it before using this
 * file.
 * 
 * The Original Code and all software distributed under the License are
 * distributed on an 'AS IS' basis, WITHOUT WARRANTY OF ANY KIND, EITHER
 * EXPRESS OR IMPLIED, AND APPLE HEREBY DISCLAIMS ALL SUCH WARRANTIES,
 * INCLUDING WITHOUT LIMITATION, ANY WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE, QUIET ENJOYMENT OR NON-INFRINGEMENT.
 * Please see the License for the specific language governing rights and
 * limitations under the License.
 * 
 * @APPLE_LICENSE_HEADER_END@
 */

#ifndef _SCDYNAMICSTORECOPYSPECIFIC_H
#define _SCDYNAMICSTORECOPYSPECIFIC_H

#include <sys/cdefs.h>
#include <CoreFoundation/CoreFoundation.h>
#include <SystemConfiguration/SCDynamicStore.h>


/*!
	@header SCDynamicStoreCopySpecific
	The following APIs allow an application to determine specific
	configuration information about the current system (e.g. the
	computer/sharing name, the currently logged in user, etc).
 */


__BEGIN_DECLS

/*!
	@function SCDynamicStoreCopyComputerName
	@discussion Gets the current computer/host name.
	@param store An SCDynamicStoreRef that should be used for communication
		with the server.
		If NULL, a temporary session will be used.
	@param nameEncoding A pointer to memory that, if non-NULL, will be
		filled with the encoding associated with the computer/host name.
	@result The current computer/host name;
		NULL if the name has not been set or if an error was encountered.
		You must release the returned value.
 */
CFStringRef
SCDynamicStoreCopyComputerName		(
					SCDynamicStoreRef	store,
					CFStringEncoding	*nameEncoding
					);

/*!
	@function SCDynamicStoreCopyConsoleUser
	@discussion Gets the name, user ID, and group ID of the currently
		logged in user.
	@param store An SCDynamicStoreRef that should be used for communication
		with the server.
		If NULL, a temporary session will be used.
	@param uid A pointer to memory that will be filled with the user ID
		of the current "Console" user. If NULL, this value will not
		be returned.
	@param gid A pointer to memory that will be filled with the group ID
		of the current "Console" user. If NULL, this value will not be
		returned.
	@result The current user logged into the system;
		NULL if no user is logged in or if an error was encountered.
		You must release the returned value.
 */
CFStringRef
SCDynamicStoreCopyConsoleUser		(
					SCDynamicStoreRef	store,
					uid_t			*uid,
					gid_t			*gid
					);

/*!
	@function SCDynamicStoreCopyLocalHostName
	@discussion Gets the current local host name.

		See SCDynamicStoreKeyCreateHostNames() for notification
		key information.
	@param store An SCDynamicStoreRef that should be used for communication
		with the server.
		If NULL, a temporary session will be used.
	@result The current local host name;
		NULL if the name has not been set or if an error was encountered.
		You must release the returned value.
 */
CFStringRef
SCDynamicStoreCopyLocalHostName		(
					SCDynamicStoreRef	store
					);

/*!
	@function SCDynamicStoreCopyLocation
	@discussion Gets the current "location" identifier.
	@param store An SCDynamicStoreRef that should be used for communication
		with the server.
		If NULL, a temporary session will be used.
	@result A string representing the current "location" identifier;
		NULL if no "location" identifier has been defined or if an error
		was encountered.
		You must release the returned value.
 */
CFStringRef
SCDynamicStoreCopyLocation		(
					SCDynamicStoreRef	store
					);

/*!
	@function SCDynamicStoreCopyProxies
	@discussion Gets the current internet proxy settings.
	@param store An SCDynamicStoreRef that should be used for communication
		with the server.
		If NULL, a temporary session will be used.
	@result A dictionary with key/value pairs representing the current
		internet proxy settings (HTTP, FTP, etc);
		NULL if no proxy settings have been defined or if an error was encountered.
		You must release the returned value.
 */
CFDictionaryRef
SCDynamicStoreCopyProxies		(
					SCDynamicStoreRef	store
					);

__END_DECLS

#endif /* _SCDYNAMICSTORECOPYSPECIFIC_H */
