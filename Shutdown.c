#include <proto/dos.h>
#include <proto/exec.h>
#include <proto/acpi.h>

#include <dos/dos.h>
#include <exec/exec.h>
#include <dos/errors.h>
#include <resources/acpi.h>

#include "Shutdown_rev.h"

USED CONST_STRPTR version = VERSTAG;

int main(void)
{
	struct ACPIIFace *IACPI;
	uint32 supports_shutdown = FALSE;

	/* Open the resource */
	IACPI = IExec->OpenResource("acpi.resource");

	/* Check if shutdown is supported */
	if (IACPI != NULL)
	    IACPI->GetAttr(ACPIA_ShutdownSupported, &supports_shutdown);

	if (supports_shutdown)
	{
	    APTR stack;

	    /* Enter supervisor mode */
		stack = IExec->SuperState();

	    IACPI->Shutdown();

	    /* This point should never be reached, but clean up anyway */
	    if (stack != NULL)
	    {
			IExec->UserState(stack);
	    }
	}
	else
	{
	    /* Shutdown is not supported on this machine/OS combination */
		IDOS->SetIoErr(ERROR_UNSUPPORTED_HARDWARE);
		return RETURN_ERROR;
	}

	/* this shall never happen */
	IDOS->SetIoErr(ERROR_NOT_IMPLEMENTED);
	return RETURN_FAIL;
}
