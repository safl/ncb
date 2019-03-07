#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <liblightnvm.h>

int dump(struct nvm_nvme_cmd *cmd, const char *fpath)
{
	FILE *fhandle = NULL;
	size_t fcount = 0;

	fhandle = fopen(fpath, "wb");
	fcount = fwrite(cmd, 1, sizeof(*cmd), fhandle);
	fclose(fhandle);

	if (fcount != sizeof(*cmd)) {
		errno = EINVAL;
		return -1;
	}

	return 0;
}

int main(int argc, char *argv[])
{
	struct nvm_nvme_cmd cmd = { 0 };

	if (argc < 2) {
		printf("usage: %s FILE_FPATH\n", argv[0]);
		return 1;
	}

	// Construct the command bits here
	cmd.opcode = NVM_DOPC_SCALAR_READ;
	cmd.nsid = 1;
	cmd.nvme.naddrs = 3;

	if (dump(&cmd, argv[1])) {
		perror("dump");
		return 1;
	}

	return 0;
}
