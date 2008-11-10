/*
 * __xmknod() wrapper.
 *
 * Copyright 1999-2008 Gentoo Foundation
 * Licensed under the GPL-2
 *
 *  Partly Copyright (C) 1998-9 Pancrazio `Ezio' de Mauro <p@demauro.net>,
 *  as some of the InstallWatch code was used.
 */

#define WRAPPER_ARGS int ver, const char *pathname, __mode_t mode, __dev_t *dev
extern int EXTERN_NAME(WRAPPER_ARGS);
static int (*WRAPPER_TRUE_NAME)(WRAPPER_ARGS) = NULL;

int WRAPPER_NAME(WRAPPER_ARGS)
{
	int result = -1;

	if FUNCTION_SANDBOX_SAFE(STRING_NAME, pathname) {
		check_dlsym(WRAPPER_TRUE_NAME, WRAPPER_SYMNAME,
			    WRAPPER_SYMVER);
		result = WRAPPER_TRUE_NAME(ver, pathname, mode, dev);
	}

	return result;
}
