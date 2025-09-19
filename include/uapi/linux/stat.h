#ifndef _UAPI_LINUX_STAT_H
#define _UAPI_LINUX_STAT_H

#include <linux/types.h>

#if !defined(__KERNEL__)
#include <asm/stat.h>
#endif

#define S_IFMT  00170000
#define S_IFSOCK 0140000
#define S_IFLNK	 0120000
#define S_IFREG  0100000
#define S_IFBLK  0060000
#define S_IFDIR  0040000
#define S_IFCHR  0020000
#define S_IFIFO  0010000

#define S_ISUID  0004000
#define S_ISGID  0002000
#define S_ISVTX  0001000

#define S_ISLNK(m)	(((m) & S_IFMT) == S_IFLNK)
#define S_ISREG(m)	(((m) & S_IFMT) == S_IFREG)
#define S_ISDIR(m)	(((m) & S_IFMT) == S_IFDIR)
#define S_ISCHR(m)	(((m) & S_IFMT) == S_IFCHR)
#define S_ISBLK(m)	(((m) & S_IFMT) == S_IFBLK)
#define S_ISFIFO(m)	(((m) & S_IFMT) == S_IFIFO)
#define S_ISSOCK(m)	(((m) & S_IFMT) == S_IFSOCK)

#define S_IRWXU 00700
#define S_IRUSR 00400
#define S_IWUSR 00200
#define S_IXUSR 00100

#define S_IRWXG 00070
#define S_IRGRP 00040
#define S_IWGRP 00020
#define S_IXGRP 00010

#define S_IRWXO 00007
#define S_IROTH 00004
#define S_IWOTH 00002
#define S_IXOTH 00001


/*
 * Structure for the statx() system call
 */

struct statx_timestamp {
	__s64	tv_sec;
	__u32	tv_nsec;
	__s32	__reserved;
};

struct statx {
	__u32	stx_mask;	/* What results were written [uncond] */
	__u32	stx_blksize;	/* Preferred general I/O size [uncond] */
	__u64	stx_attributes;	/* Flags conveying information about the file [uncond] */
	__u32	stx_nlink;	/* Number of hard links */
	__u32	stx_uid;	/* User ID of owner */
	__u32	stx_gid;	/* Group ID of owner */
	__u16	stx_mode;	/* File type and mode */
	__u16	__spare0[1];
	__u64	stx_ino;	/* Inode number */
	__u64	stx_size;	/* Total size in bytes */
	__u64	stx_blocks;	/* Number of 512B blocks allocated */
	__u64	stx_attributes_mask;/* Atts returned to user */
	struct statx_timestamp	stx_atime;	/* Last access */
	struct statx_timestamp	stx_btime;	/* Creation */
	struct statx_timestamp	stx_ctime;	/* Last status change */
	struct statx_timestamp	stx_mtime;	/* Last modification */
	__u32	stx_rdev_major;	/* Major ID */
	__u32	stx_rdev_minor;	/* Minor ID */
	__u32	stx_dev_major;	/* Major ID */
	__u32	stx_dev_minor;	/* Minor ID */
	__u64	__spare2[14];	/* Spare space for future expansion */
};

/*
 * Flags for the stx_mask field
 */
#define STATX_TYPE		0x00000001U	/* Want stx_mode & S_IFMT */
#define STATX_MODE		0x00000002U	/* Want stx_mode & ~S_IFMT */
#define STATX_NLINK		0x00000004U	/* Want stx_nlink */
#define STATX_UID		0x00000008U	/* Want stx_uid */
#define STATX_GID		0x00000010U	/* Want stx_gid */
#define STATX_ATIME		0x00000020U	/* Want stx_atime */
#define STATX_MTIME		0x00000040U	/* Want stx_mtime */
#define STATX_CTIME		0x00000080U	/* Want stx_ctime */
#define STATX_INO		0x00000100U	/* Want stx_ino */
#define STATX_SIZE		0x00000200U	/* Want stx_size */
#define STATX_BLOCKS		0x00000400U	/* Want stx_blocks */
#define STATX_BASIC_STATS	0x000007ffU	/* The stuff in the normal stat struct */
#define STATX_BTIME		0x00000800U	/* Want stx_btime */
#define STATX_ALL		0x00000fffU	/* All currently supported flags */


#endif /* _UAPI_LINUX_STAT_H */
